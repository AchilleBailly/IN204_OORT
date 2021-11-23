#pragma once
#include <cmath>
#include <SFML/System.hpp>
using namespace sf;

class Vector : public Vector3<double>
{

public:
    Vector3 vec;
    bool unit;

    Vector() : vec() {}
    Vector(double X, double Y, double Z) : vec(X, Y, Z) {}
    Vector(double X, double Y, double Z, bool is_unit) : vec(X, Y, Z), unit(is_unit)
    {
        if (is_unit)
        {
            double n = (*this).norm;
            x = X / n;
            y = Y / n;
            z = Z / n;
        }
    }
    Vector(const Vector &v) : vec(v) {}
    Vector(const Vector &v, bool is_unit) { Vector(v.x, v.y, v.z, is_unit); }

    double operator*(Vector Vec)
    {
        return vec.x * Vec.vec.x + vec.y * Vec.vec.y + vec.z * Vec.vec.z;
    }

    double norm()
    {
        if (unit)
            return 1;
        return std::sqrt((*this) * (*this));
    }
};