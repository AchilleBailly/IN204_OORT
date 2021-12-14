#pragma once

#include "Object3D.hpp"

struct Plane : public Object3D {
  Vector orientation;

  Plane() : Object3D() {}
  Plane(const Vector &Position, const Vector &Orientation,
        shared_ptr<Material> material)
      : Object3D(Position, material), orientation(Orientation) {
    orientation = orientation / orientation.norm();
  }
};