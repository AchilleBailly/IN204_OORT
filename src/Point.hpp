#pragma once

#include "Vector.hpp"

// class Point : public Vector {
// public:
//   Point() : Vector() {}
//   Point(double x, double y, double z) : Vector(x, y, z) {}
//   Point(const Point &p) : Vector(p.x, p.y, p.z) {}
//   Point(Vector v) : Vector(v) {}

//   Vector operator-(const Point &other_point) const {
//     return *this - other_point;
//   }

//   double distance(const Point &other_point) {
//     return ((*this) - other_point).norm();
//   }
// };

// inline Point operator+(Point p, Vector v) { return ((Vector)p + v); }
// Point operator+(Vector v, Point p)
// {
//     return (p + v);
// }