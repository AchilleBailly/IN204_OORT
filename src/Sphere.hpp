#pragma once

#include "Hit_record.hpp"
#include <memory>

class Sphere : public Object3D {
public:
  double radius;

  Sphere() : Object3D(), radius(0) {}

  // radius, color (rgb), position, reflectance, transparence, indice of
  // reefraction
  Sphere(double rad, Vector p, shared_ptr<Material> mat)
      : Object3D(p, mat), radius(rad) {}

  virtual bool intersection(const Ray &ray, const double &t_min,
                            const double &t_max,
                            Hit_record &hit_rec) const override {
    Vector tmp = ray.origin - position;
    double norm_tmp2 = tmp.norm2();
    double ps = tmp.dot(ray.direction);

    double delta = ps * ps - (norm_tmp2 - radius * radius);

    if (delta <= 0) {
      // std::cout << ray << "\n" << *this;
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
       << "Position : " << s.position << std::endl;
    return os;
  }
};

inline void Sphere::update_hit(const Ray &ray, Hit_record &hit) const {
  hit.hit_point = ray.direction * hit.t + ray.origin;
  hit.normal = hit.hit_point - position;
  hit.normal.normalize();
  if (hit.normal.dot(ray.direction) > 0) {
    hit.normal *= -1;
    hit.inside_hit = true;
  } else {
    hit.inside_hit = false;
  }
}