#pragma once
#include <cmath>
#include <SFML/System.hpp>
using namespace sf;

class Vector : public Vector3<double>
{
public:
    Vector() : Vector3() {}
    Vector(double X, double Y, double Z) : Vector3(X, Y, Z) {}
    Vector(const Vector &v) : Vector(v.x, v.y, v.z) {}
    Vector(Vector3 v) : Vector(v.x, v.y, v.z) {}

    double dot(const Vector &Vec) const
    {
        return x * Vec.x + y * Vec.y + z * Vec.z;
    }

    double norm()
    {
        return std::sqrt((*this).dot(*this));
    }

    void normalize()
    {
        (*this) /= (*this).norm();
    }
};

Vector operator*(const Vector& vec, double scalar){
    return Vector(vec.x * scalar, vec.y * scalar, vec.z*scalar);
}