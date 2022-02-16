#pragma once

#include "../Object3D.hpp"
#include "Material.hpp"

class Transparent : public Material {
public:
  double ior = 1.0;
  double reflectivity = 1.0;
  Vector absorption = 1;

  Transparent() {}
  Transparent(double indice_of_refraction, double Reflectivity,
              Vector Absorption = Vector(0))
      : ior(indice_of_refraction), reflectivity(Reflectivity),
        absorption(Absorption) {}

  virtual bool scatter(const Ray &ray, Hit_record &hit,
                       std::vector<Ray> &reflected_refracted) override {
    // assuming outside it's air for now
    double n1 = (hit.inside_hit) ? ior : 1.0;
    double n2 = (hit.inside_hit) ? 1.0 : ior;
    double reflection_ratio =
        FresnelReflectAmount(n1, n2, hit.normal, ray.direction);

    Ray reflected = reflect(ray, hit);
    reflected_refracted.push_back(reflected);

    // total internal reflection, no refracted ray
    if (reflection_ratio == 1.0) {
      reflected_refracted[0].attenuation = Vector(1);
      return true;
    }

    reflected_refracted.push_back(refract(ray, hit, n1 / n2));
    reflected_refracted[0].attenuation = Vector(reflection_ratio) * 2;
    reflected_refracted[1].attenuation =
        Vector(1 - reflection_ratio) * 2 *
        ((hit.inside_hit) ? exp(-absorption * hit.t) : 1);

    return true;
  }

  Ray reflect(const Ray &ray, const Hit_record &hit) {
    Vector dir = ray.direction - 2 * hit.normal * hit.normal.dot(ray.direction);
    return Ray(hit.hit_point, dir);
  };

  Ray refract(const Ray &ray, const Hit_record &hit, double n1n2) {
    double cos_theta = std::min(-hit.normal.dot(ray.direction), 1.0);
    Vector perp = n1n2 * (ray.direction + cos_theta * hit.normal);
    Vector parallel = -sqrt(abs(1 - perp.norm2())) * hit.normal;
    return Ray(hit.hit_point, perp + parallel);
  }

  double FresnelReflectAmount(double n1, double n2, Vector normal,
                              Vector incident) {
    // Schlick aproximation
    double r0 = (n1 - n2) / (n1 + n2);
    r0 *= r0;
    double cosX = -normal.dot(incident);
    if (n1 > n2) {
      double n = n1 / n2;
      double sinT2 = n * n * (1.0 - cosX * cosX);
      if (sinT2 > 1.0) // total internal reflection
        return 1.0;
      cosX = sqrt(1.0 - sinT2);
    }
    double x = 1.0 - cosX;
    double ret = r0 + (1.0 - r0) * x * x * x * x * x;

    ret = (reflectivity + (1.0 - reflectivity) * ret);
    return ret;
  }

  virtual json to_json() override {
      json out;
      out = {
          {"type", "transparent"},
          {"ior", ior},
          {"reflectivity", reflectivity},
          {"absorption", absorption.to_json()}
      };
      return out;
  }
};
