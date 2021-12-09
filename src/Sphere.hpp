#pragma once

#include "Object3D.hpp"

class Sphere : public Object3D {
public:
  double radius;

  Sphere() : Object3D(), radius(1) {}
  Sphere(double rad, Vector c, Vector p, double r, double t, double i)
      : Object3D(p, c, r, t, i), radius(r) {}
};