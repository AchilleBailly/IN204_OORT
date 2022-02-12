#pragma once

#include "../Object3D.hpp"
#include "Material.hpp"

class Diffuse : public Material {
  Vector albedo;

public:
  Diffuse(Vector color) : albedo(color) {}

  virtual bool scatter(const Ray &r_in, Hit_record &rec,
                       std::vector<Ray> &scattered) override {
    Vector dir = rec.normal + random_unit_sphere().normalize();
    if (dir.near_zero(1e-5))
      dir = rec.normal;
    Ray ray(rec.hit_point, dir);
    ray.attenuation = albedo;
    scattered.push_back(ray);
    rec.color = 2 * albedo * rec.normal.dot(dir);
    return true;
  }
};