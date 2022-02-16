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
  QString label;

  Object3D() : position(), material() {}
  Object3D(const Vector &p, shared_ptr<Material> Material) : position(p) {
    material = Material;
  }

  virtual ~Object3D() {}

  virtual bool intersection(const Ray &ray, const double &t_min,
                            const double &t_max,
                            Hit_record &hit_record) const = 0;

  virtual void update_hit(const Ray &ray, Hit_record &hit) const = 0;

  void setLabel(const QString& Label) {label = Label;}

  friend QDebug operator<<(QDebug, const Object3D &);

  virtual json to_json() = 0;

  //virtual shared_ptr<Object3D> from_json() = 0;
};


