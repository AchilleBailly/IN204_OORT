#pragma once

#include "../Object3D.hpp"
#include "../Vector.hpp"
#include "Material.hpp"
#include <vector>

class TestMaterial : public Material {
public:
  Vector color;

  TestMaterial(Vector Color) : color(Color) {}

  virtual bool scatter(const Ray &, Hit_record &hit,
                       std::vector<Ray> &) {
    hit.color = color;
    return false;
  }

  virtual json to_json() override {
      json out = {
        {"type", "testmaterial"},
        {"color", color.to_json()}
      };
      return out;
  }
};
