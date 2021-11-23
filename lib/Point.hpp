#pragma once

#include "Vector.hpp"

class Point : public Vector
{
public:
    Point() : Vector() {}
    Point(double x, double y, double z) : Vector(x, y, z) {}
    Point(const Point &p) : Vector(p.x, p.y, p.z) {}
    Point(Vector v) : Vector(v) {}

    Vector operator-(Point other_point)
    {
        return vec - other_point.vec;
    }
};

Point operator+(Point p, Vector v)
{
    return (Vector)(p.vec + v);
}
