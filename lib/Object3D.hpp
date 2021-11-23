#pragma once

#include <SFML/Graphics.hpp>
#include "Point.hpp"
#include "Sphere.hpp"

class Object3D
{
public:
    sf::Color color;
    Vector orientation;
    Point position;
    double reflectance;
    double transparence;
    double indice_refraction;

    Object3D() : color(), orientation(), position(), reflectance(1), transparence(0), indice_refraction(0) {}
    Object3D(sf::Color c, Point p, double r, double t, double i) : color(c), orientation(), position(p), reflectance(r), transparence(t), indice_refraction(i) {}
};