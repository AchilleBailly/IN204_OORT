#pragma once

#include "Object3D.hpp"

struct Plane : public Object3D
{
    Plane() : Object3D() {}
    Plane(const Point &p, const Vector &v, sf::Color c, double r, double t, double i) : Object3D(p, v, c, r, t, i)
    {
        orientation = orientation / orientation.norm();
    }
};