#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <ostream>
#include <random>
#include "QDebug"

// Common Headers

#include "Ray.hpp"
#include "Vector.hpp"

// Usings

using std::make_shared;
using std::shared_ptr;
using std::sqrt;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
  return degrees * pi / 180.0;
}

inline double random_double(double min, double max) {
  static std::uniform_real_distribution<double> distribution(0., 1.);
  static std::mt19937 generator;
  return distribution(generator) * (max - min) + min;
}

inline Vector random_unit_sphere() {
  Vector res;
  do {
    double x = random_double(-1., 1.);
    double y = random_double(-1., 1.);
    double z = random_double(-1., 1.);
    res = {x, y, z};
  } while (res.norm2() > 1.0);
  return res;
}

inline Vector random_hemisphere(const Vector &dir) {
  Vector res;
  do {
    res = random_unit_sphere();
  } while (res.dot(dir) <= 0);
  return res;
}

#endif
