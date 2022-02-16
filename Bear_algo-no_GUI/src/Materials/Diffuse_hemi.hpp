
#pragma once

#include "../Object3D.hpp"
#include "Material.hpp"

class Diffuse_hemi : public Material {
  Vector albedo;

public:
  Diffuse_hemi(Vector color) : albedo(color) {}

  virtual bool scatter(const Ray &r_in, Hit_record &rec,
                       std::vector<Ray> &scattered) override {
    Vector rand = random_unit_sphere().normalize();
    Vector dir = ((rand.dot(rec.normal) < 0) ? -1 : 1) * rand;
    Ray ray(1e-4 * rec.normal + rec.hit_point, dir);
    ray.attenuation = albedo;
    scattered.push_back(ray);
    rec.color = 2 * albedo * dir.dot(rec.normal);
    return true;
  }
};