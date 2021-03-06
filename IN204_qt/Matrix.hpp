#pragma once

#include "utils.hpp"
#include <vector>

class Matrix {
  std::vector<Vector> *m_values = new std::vector<Vector>(3);

public:
  Matrix() {
    m_values->at(0) = Vector(0);
    m_values->at(1) = Vector(0);
    m_values->at(2) = Vector(0);
  }
  Matrix(Vector e1, Vector e2, Vector e3) {
    m_values->at(0) = {e1.x, e2.x, e3.x};
    m_values->at(1) = {e1.y, e2.y, e3.y};
    m_values->at(2) = {e1.z, e2.z, e3.z};
  }

  void set(const Vector &e1, const Vector &e2, const Vector &e3) {
    m_values->at(0) = {e1.x, e2.x, e3.x};
    m_values->at(1) = {e1.y, e2.y, e3.y};
    m_values->at(2) = {e1.z, e2.z, e3.z};
  }

  Vector operator*(const Vector &vec) {
    double x = m_values->at(0).x * vec.x + m_values->at(0).y * vec.y +
               m_values->at(0).z * vec.z;
    double y = m_values->at(1).x * vec.x + m_values->at(1).y * vec.y +
               m_values->at(1).z * vec.z;
    double z = m_values->at(2).x * vec.x + m_values->at(2).y * vec.y +
               m_values->at(2).z * vec.z;
    return {x, y, z};
  }

  friend QDebug operator<<(QDebug os, Matrix mat) {
    auto it = mat.m_values->begin();
    os << "[" << *(it++) << ",\n" << *(it++) << ",\n" << *(it++) << "]";
    return os;
  }
};
