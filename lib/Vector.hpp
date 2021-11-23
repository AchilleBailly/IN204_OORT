#pragma once
#include <cmath>
#include <SFML/System.hpp>
using namespace sf;

class Vector : public Vector3<double>
{

public:
    Vector3 vec;

    Vector() : vec() {}
    Vector(double X, double Y, double Z) : vec(X, Y, Z) {}
    Vector(const Vector &v) : vec(v) {}
    Vector(const Vector3 &v) : Vector(v.x, v.y, v.z) {}

    double operator*(Vector Vec)
    {
        return vec.x * Vec.vec.x + vec.y * Vec.vec.y + vec.z * Vec.vec.z;
    }

    double norm()
    {
        return std::sqrt((*this) * (*this));
    }
};

Vector operator*(double scalar, Vector V)
{
    return V.vec * scalar;
}

Vector operator*(Vector V, double scalar)
{
    return V.vec * scalar;
}
