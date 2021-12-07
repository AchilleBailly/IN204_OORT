#pragma once

#include "Sphere.hpp"
#include "Representation.hpp"
#include "Plane.hpp"
using namespace sf;

class Ray : public Point
{
public:
    Point origin;
    Vector direction;

    Ray() : origin(), direction() {}
    Ray(const Point &ori, const Vector &dir) : origin(ori), direction(dir) {}

    Point intersection(const Sphere &S) const
    {
        Vector tmp = origin - S.position;
        double norm_dir2 = direction.dot(direction);
        double norm_tmp2 = tmp.dot(tmp);
        double ps = tmp.dot(direction);

        double delta = 4 * (pow(ps, 2) - norm_dir2 * (norm_tmp2 - S.radius * S.radius));

        if (delta <= 0)
            return Point(INFINITY, INFINITY, INFINITY);
        else
        {
            double t1 = -ps / norm_tmp2 - delta / (2 * norm_tmp2);
            double t2 = -ps / norm_tmp2 + delta / (2 * norm_tmp2);
            if (t1 > 0)
                return (Point)origin + (Vector)(direction * t1);
            else if (t2 > 0)
                return (Point)origin + (Vector)(direction * t2);
            else
                return Point(INFINITY, INFINITY, INFINITY);
        }
    }

    Vector c_normal(const Sphere &S, const Point &intersection) const
    {
        Vector res = intersection - S.position;
        res.normalize();
        if (res.dot((*this).direction) >= 0)
            return -res;
        else
            return res;
    }

    Point intersection(const Plane &plane) const
    {
        double ps = direction.dot(plane.orientation);
        if (ps == 0) // very unlikely with floats, should be replaced by a view distance
            return Point(INFINITY, INFINITY, INFINITY);
        else
        {
            Point res = direction - tan(ps) * plane.orientation;
            return res;
        }
    }

    Vector c_normal(const Plane &P, const Point &intersection) const
    {
        if ((*this).direction.dot(P.orientation) <= 0)
            return P.orientation;
        else
            return -P.orientation;
    }
};