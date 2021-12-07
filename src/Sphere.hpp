#pragma once

#include "Object3D.hpp"

class Sphere : public Object3D
{
public:
    double radius;

    Sphere() : radius(1), Object3D() {}
    Sphere(double rad, sf::Color c, Point p, double r, double t, double i) : Object3D(p, c, r, t, i), radius(r) {}
};