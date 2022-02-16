#pragma once

#include "json.hpp"
#include "utils.hpp"
#include <algorithm>
#include <memory>
using json = nlohmann::json;
#include <fstream>
#include <string>

class Vector;
class Ray;
class Hit_record;
class Material;

class Object3D {
public:
  Vector position;
  shared_ptr<Material> material;

  Object3D() : position(), material() {}
  Object3D(const Vector &p, shared_ptr<Material> Material) : position(p) {
    material = Material;
  }

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