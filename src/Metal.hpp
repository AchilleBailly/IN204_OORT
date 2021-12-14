#pragma once

#include "Material.hpp"
#include <vector>

class Metal : public Material {
public:
  Metal(const Vector &a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

  virtual bool scatter(const Ray &r_in, Hit_record &rec,
                       std::vector<Ray> &scattered) override {
    Ray reflected = reflect(r_in, rec);
    scattered.push_back(reflected);
    scattered[0].attenuation = albedo;
    return true;
  }

  Ray reflect(const Ray &ray, const Hit_record &hit) {
    Vector dir = ray.direction - 2 * hit.normal * hit.normal.dot(ray.direction);
    return Ray(hit.hit_point, dir);
  };

public:
  Vector albedo;
  double fuzz;
};