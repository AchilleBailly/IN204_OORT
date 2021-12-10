#pragma once

#include "Object3D.hpp"
#include "Vector.hpp"
#include <cstddef>
#include <memory>

class Hit_record {
public:
  double t = 0;
  Vector hit_point = 0;
  Vector normal = 0;
  std::shared_ptr<Object3D> obj_hit = NULL;

  Hit_record() {}

  Hit_record(double T, Vector Hit, Vector Normal)
      : t(T), hit_point(Hit), normal(Normal) {}
};