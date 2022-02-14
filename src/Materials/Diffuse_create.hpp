#pragma once

#include "Material.hpp"

class Diffuse_create : public Material {
  Vector albedo;
  int nb_ray_created = 1;

public:
  Diffuse_create(Vector color, int Rays_created)
      : albedo(color), nb_ray_created(Rays_created) {}

  virtual bool scatter(const Ray &ray, Hit_record &hit_record,
                       std::vector<Ray> &ray_list) override {
    for (int i = 0; i < nb_ray_created; i++) {
      Ray scattered(hit_record.hit_point, random_hemisphere(hit_record.normal));
      scattered.attenuation =
          2 * albedo * scattered.direction.dot(hit_record.normal);
      ray_list.push_back(scattered);
    }
    return true;
  }
};