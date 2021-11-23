#pragma once

#include <SFML/Graphics.hpp>
#include "Point.hpp"

class Object3D
{
public:
    sf::Color color;
    Vector orientation;
    Point position;
    double reflectance;
    double tranparence;
    double indice_refraction;
};