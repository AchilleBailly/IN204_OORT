#pragma once

#include "Material.hpp"

class LightSource : public Material {
public:
  LightSource(Vector Color) : color(Color) {}

  virtual bool scatter(const Ray &, Hit_record &hit_record,
                       std::vector<Ray> &) {
    hit_record.color = color;
    return false;
  }
  Vector color;
};
