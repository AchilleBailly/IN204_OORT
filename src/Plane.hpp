#pragma once

#include "Object3D.hpp"

struct Plane : public Object3D {
  Plane() : Object3D() {}
  Plane(const Vector &p, const Vector &v, Vector c, double r, double t,
        double i)
      : Object3D(p, v, c, r, t, i) {
    orientation = orientation / orientation.norm();
  }
};