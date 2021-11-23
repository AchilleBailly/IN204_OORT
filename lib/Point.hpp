#pragma once

#include "Vector.hpp"

class Point : public Vector
{
public:
    Point() : Vector() {}
    Point(double x, double y, double z) : Vector(x, y, z) {}
    Point(const Point &p) : Vector(p.x, p.y, p.z) {}
};
