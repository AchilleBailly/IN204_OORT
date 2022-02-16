#pragma once

#include "Vector.hpp"
#include <iostream>
#include <ostream>

class Ray : public Vector {
public:
  Vector origin;
  Vector direction;
  Vector attenuation;

  Ray() : origin(), direction() {}
  Ray(const Vector &ori, const Vector &dir) : origin(ori), direction(dir) {
    direction.normalize();
  }

  friend QDebug operator<<(QDebug os, const Ray &ray) {
    os << "[Ray object]\n";
    os << "Origin : " << ray.origin ;
    os << "Direction : " << ray.direction;
    return os;
  }
};
