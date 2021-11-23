#pragma once

#include "Point.hpp"
using namespace sf;

class Ray : public Point
{
public:
    Point origin;
    Vector direction;

    Ray() : origin(), direction() {}
    Ray(const Point &ori, const Vector &dir) : origin(ori), direction(dir, 1) {}
};