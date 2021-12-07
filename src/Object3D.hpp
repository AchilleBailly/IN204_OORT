#pragma once

#include "json.hpp"
using json = nlohmann::json;
#include <SFML/Graphics.hpp>
#include "Point.hpp"
#include <iostream>
#include <fstream>
#include <string>

class Point;

class Object3D
{
public:
    sf::Color color;
    Vector orientation;
    Point position;
    double reflectance;
    double transparence;
    double indice_refraction;
    sf::Color emissionColor;

    Object3D() : color(), orientation(), position(), reflectance(1), transparence(0), indice_refraction(0) {}
    Object3D(const Point &p, sf::Color c, double r, double t, double i) : color(c), orientation(), position(p), reflectance(r), transparence(t), indice_refraction(i) {}
    Object3D(const Point &p, const Vector &v, sf::Color c, double r, double t, double i) : color(c), orientation(v), position(p), reflectance(r), transparence(t), indice_refraction(i) {}
};

void load_from_json(std::string file_name)
{
    std::fstream input;
    input.open(file_name);

    json j;
    input >> j;
    std::cout << j;
}