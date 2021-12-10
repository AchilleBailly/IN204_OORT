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
class Ray;
class Hit_record;

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
  Object3D(const Vector &p, Vector c, double r, double t, double i, Vector ec)
      : color(c), orientation(), position(p), reflectance(r), transparence(t),
        indice_refraction(i), emissionColor(ec) {}
  Object3D(const Vector &p, const Vector &v, Vector c, double r, double t,
           double i)
      : color(c), orientation(v), position(p), reflectance(r), transparence(t),
        indice_refraction(i) {}

  virtual ~Object3D() {}

  virtual bool intersection(const Ray &ray, const double &t_min,
                            const double &t_max,
                            Hit_record &hit_record) const = 0;

  virtual void update_hit(const Ray &ray, Hit_record &hit) const = 0;
};

inline void load_from_json(std::string file_name) {
  std::fstream input;
  input.open(file_name);

  json j;
  input >> j;
  std::cout << j;
}