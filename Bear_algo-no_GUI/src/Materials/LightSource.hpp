#pragma once

#include "Material.hpp"

class LightSource : public Material {
  Vector color;

public:
  LightSource(Vector Color) : color(Color) {}

  virtual bool scatter(const Ray &ray, Hit_record &hit_record,
                       std::vector<Ray> &ray_list) {
    hit_record.color = color;
    return false;
  }
};