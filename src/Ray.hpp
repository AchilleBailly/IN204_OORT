#pragma once

#include "Vector.hpp"
#include <iostream>
#include <ostream>

class Ray : public Vector {
public:
  Vector origin;
  Vector direction;

  Ray() : origin(), direction() {}
  Ray(const Vector &ori, const Vector &dir) : origin(ori), direction(dir) {
    direction.normalize();
  }

  // Vector intersection(Sphere S) const {
  //   Vector tmp = origin - S.position;
  //   double norm_tmp2 = tmp.norm2();
  //   double ps = tmp.dot(direction);

  //   double delta = ps * ps - (norm_tmp2 - S.radius * S.radius);

  //   if (delta <= 0) {
  //     return Vector(INFINITY, INFINITY, INFINITY);
  //   } else {
  //     double t1 = -ps - sqrt(delta);
  //     double t2 = -ps + sqrt(delta);
  //     if (t1 > 0)
  //       return origin + (direction * t1);
  //     else if (t2 > 0)
  //       return origin + (direction * t2);
  //     else
  //       return Vector(INFINITY, INFINITY, INFINITY);
  //   }
  // }

  // Vector c_normal(const Sphere &S, const Vector &intersection) const {
  //   Vector res = intersection - S.position;
  //   res.normalize();
  //   if (res.dot((*this).direction) >= 0)
  //     return -res;
  //   else
  //     return res;
  // }

  // Vector intersection(const Plane &plane) const {
  //   double ps = direction.dot(plane.orientation);
  //   if (ps ==
  //       0) // very unlikely with floats, should be replaced by a view
  //       distance
  //     return Vector(INFINITY, INFINITY, INFINITY);
  //   else {
  //     Vector res = direction - tan(ps) * plane.orientation;
  //     return res;
  //   }
  // }

  // Vector c_normal(const Plane &P, const Vector &intersection) const {
  //   if ((*this).direction.dot(P.orientation) <= 0)
  //     return P.orientation;
  //   else
  //     return -P.orientation;
  // }

  friend std::ostream &operator<<(std::ostream &os, const Ray &ray) {
    os << "[Ray object]\n";
    os << "Origin : " << ray.origin << "\n";
    os << "Direction : " << ray.direction;
    return os;
  }
};