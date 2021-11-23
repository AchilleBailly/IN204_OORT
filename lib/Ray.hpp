#pragma once

#include "Point.hpp"
#include "Object3D.hpp"
using namespace sf;

class Ray : public Point
{
public:
    Point origin;
    Vector direction;

    Ray() : origin(), direction() {}
    Ray(const Point &ori, const Vector &dir) : origin(ori), direction(dir) {}

    Point intersection(Sphere S)
    {
        Vector tmp = S.position - origin;
        double ray_point = tmp * direction;
        Point projete = origin + direction * ray_point;
        // a finir
    }
};