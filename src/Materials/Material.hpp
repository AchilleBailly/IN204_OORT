#pragma once

#include "../Hit_record.hpp"
#include "../utils.hpp"

class Material {
public:
  virtual bool scatter(const Ray &ray, Hit_record &hit_record,
                       std::vector<Ray> &ray_list) = 0;

  Material() {}
  virtual ~Material() {}
};