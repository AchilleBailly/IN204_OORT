#pragma once

#include "Vector.hpp"
#include <iostream>
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
    m_values->at(0) = (e1);
    m_values->at(1) = (e2);
    m_values->at(2) = (e3);
  }

  void set(const Vector &e1, const Vector &e2, const Vector &e3) {
    m_values->at(0) = e1;
    m_values->at(1) = e2;
    m_values->at(2) = e3;
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

  friend std::ostream &operator<<(std::ostream &os, Matrix mat) {
    auto it = mat.m_values->begin();
    std::cout << "[" << *(it++) << ",\n" << *(it++) << ",\n" << *(it++) << "]";
    return os;
  }
};