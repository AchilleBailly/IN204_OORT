#pragma once

#include "Hit_record.hpp"
#include "Object3D.hpp"
#include "Ray.hpp"
#include <ostream>

class Sphere : public Object3D {
public:
  double radius;

  Sphere() : Object3D(), radius(0) {}

  // radius, color (rgb), position, reflectance, transparence, indice of
  // reefraction
  Sphere(double rad, Vector c, Vector p, double t, double r, double i = 1.0,
         Vector ec = 0)
      : Object3D(p, c, r, t, i, ec), radius(r) {}

  virtual bool intersection(const Ray &ray, const double &t_min,
                            const double &t_max,
                            Hit_record &hit_rec) const override {
    Vector tmp = ray.origin - position;
    double norm_tmp2 = tmp.norm2();
    double ps = tmp.dot(ray.direction);

    double delta = ps * ps - (norm_tmp2 - radius * radius);

    if (delta <= 0) {
      return false;
    } else {
      double t1 = -ps - sqrt(delta);
      double t2 = -ps + sqrt(delta);
      double t;
      if (t1 > t_min && t1 < t_max)
        t = t1;
      else if (t2 > t_min && t2 < t_max)
        t = t2;
      else
        return false;
      hit_rec.t = t;
      return true;
    }
  }

  virtual void update_hit(const Ray &ray, Hit_record &hit) const override;

  friend std::ostream &operator<<(std::ostream &os, const Sphere &s) {
    os << "[Sphere object]\n"
       << "Radius : " << s.radius << std::endl
       << "Position : " << s.position << std::endl
       << "Color : " << s.color;
    return os;
  }
};

inline void Sphere::update_hit(const Ray &ray, Hit_record &hit) const {
  hit.hit_point = ray.direction * hit.t + ray.origin;
  hit.normal = hit.hit_point - position;
}