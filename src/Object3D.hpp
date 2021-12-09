#pragma once

#include "Vector.hpp"
#include "json.hpp"
using json = nlohmann::json;
#include "Vector.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>

class Vector;

class Object3D {
public:
  Vector color;
  Vector orientation;
  Vector position;
  double reflectance;
  double transparence;
  double indice_refraction;
  Vector emissionColor;

  Object3D()
      : color(), orientation(), position(), reflectance(1), transparence(0),
        indice_refraction(0) {}
  Object3D(const Vector &p, Vector c, double r, double t, double i)
      : color(c), orientation(), position(p), reflectance(r), transparence(t),
        indice_refraction(i) {}
  Object3D(const Vector &p, const Vector &v, Vector c, double r, double t,
           double i)
      : color(c), orientation(v), position(p), reflectance(r), transparence(t),
        indice_refraction(i) {}
};

inline void load_from_json(std::string file_name) {
  std::fstream input;
  input.open(file_name);

  json j;
  input >> j;
  std::cout << j;
}