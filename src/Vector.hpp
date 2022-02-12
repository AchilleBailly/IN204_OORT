#pragma once

#include <cmath>
#include <ostream>

// class Vector : public Vector3<double>
// {
// public:
//     Vector() : Vector3() {}
//     Vector(double X, double Y, double Z) : Vector3(X, Y, Z) {}
//     Vector(const Vector &v) : Vector(v.x, v.y, v.z) {}
//     Vector(Vector3 v) : Vector(v.x, v.y, v.z) {}

//     double dot(const Vector &Vec) const
//     {
//         return x * Vec.x + y * Vec.y + z * Vec.z;
//     }

//     double norm()
//     {
//         return std::sqrt((*this).dot(*this));
//     }

//     void normalize()
//     {
//         (*this) /= (*this).norm();
//     }
// };

class Vector {
public:
  double x = double(0);
  double y = double(0);
  double z = double(0);

  Vector() {}

  Vector(double const &xx) : x(xx), y(xx), z(xx) {}

  Vector(double const &xx, double const &yy, double const &zz)
      : x(xx), y(yy), z(zz) {}

  ~Vector() {}

  double norm2() const { return x * x + y * y + z * z; }

  double norm() const { return sqrt(norm2()); }

  Vector &normalize() {
    double nor2 = norm2();
    if (nor2 > 0) {
      double invNor = 1 / sqrt(nor2);
      x *= invNor, y *= invNor, z *= invNor;
    }
    return *this;
  }

  Vector operator*(const double &f) const { return {x * f, y * f, z * f}; }

  Vector operator*(const Vector &v) const {
    return Vector({x * v.x, y * v.y, z * v.z});
  }

  Vector operator/(const double &scalar) const {
    return {x / scalar, y / scalar, z / scalar};
  }

  double dot(const Vector &v) const { return x * v.x + y * v.y + z * v.z; }

  Vector operator-(const Vector &v) const {
    return {x - v.x, y - v.y, z - v.z};
  }

  Vector operator+(const Vector &v) const {
    return {x + v.x, y + v.y, z + v.z};
  }

  Vector &operator+=(const Vector &v) {
    x += v.x, y += v.y, z += v.z;
    return *this;
  }

  Vector &operator*=(const Vector &v) {
    x *= v.x, y *= v.y, z *= v.z;
    return *this;
  }

  Vector &operator/=(const double &v) {
    x /= v, y /= v, z /= v;
    return *this;
  }

  Vector operator-() const { return Vector(-x, -y, -z); }

  friend std::ostream &operator<<(std::ostream &os, const Vector &v) {
    os << "[" << v.x << ", " << v.y << ", " << v.z << "]";
    return os;
  }

  friend Vector operator*(const double &scalar, const Vector &v) {
    return {v.x * scalar, v.y * scalar, v.z * scalar};
  }

  Vector vectoriel(const Vector &vec) {
    return {y * vec.z - z * vec.y, z * vec.x - x * vec.z,
            x * vec.y - y * vec.x};
  }

  friend Vector pow(const Vector &vec, double exp) {
    return Vector(pow(vec.x, exp), pow(vec.y, exp), pow(vec.z, exp));
  }

  friend Vector exp(const Vector &vec) {
    return {exp(vec.x), exp(vec.y), exp(vec.z)};
  }

  double distance(const Vector &vec) { return (vec - *this).norm(); }

  bool near_zero(double bias) {
    if ((*this).norm2() < bias) {
      return true;
    }
    return false;
  }
};
