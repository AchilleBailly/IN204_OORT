#pragma once

#include "../Object3D.hpp"
#include "../Vector.hpp"
#include "Material.hpp"
#include <vector>

class TestMaterial : public Material {
public:
  Vector color;

  TestMaterial(Vector Color) : color(Color) {}

  virtual bool scatter(const Ray &ray, Hit_record &hit,
                       std::vector<Ray> &scattered) {
    hit.color = color;
    return false;
  }
};