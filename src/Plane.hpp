#pragma once

#include "Hit_record.hpp"

struct Plane : public Object3D {
  Vector orientation;

  Plane() : Object3D() {}
  Plane(const Vector &Position, const Vector &Orientation,
        shared_ptr<Material> material)
      : Object3D(Position, material), orientation(Orientation) {
    orientation = orientation.normalize();
  }

  virtual bool intersection(const Ray &ray, const double &t_min,
                            const double &t_max,
                            Hit_record &hit) const override {
    double t = ray.direction.dot(orientation);
    if (t == 0)
      return false;

    hit.t = (position - ray.origin).dot(orientation) / t;
    if (hit.t < t_min || hit.t > t_max)
      return false;

    return true;
  }

  virtual void update_hit(const Ray &ray, Hit_record &hit) const override {
    hit.normal =
        (orientation.dot(ray.direction) < 0) ? orientation : -orientation;
    hit.hit_point = hit.t * ray.direction + ray.origin;
  }
};