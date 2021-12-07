#pragma once

#include "Representation.hpp"
#include "json.hpp"
#include "Ray.hpp"
#include <vector>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

namespace
{
    sf::Color BG_COLOR{255, 255, 255};

    sf::Color ray_trace1(const Ray &ray, const std::vector<Sphere> &Spheres, const int &depth)
    {
        float distance = INFINITY;
        const Sphere *nearest = NULL;
        Point intersec;

        // get the nearest intersection point, if it exists
        for (int it = 0; it < Spheres.size(); it++)
        {
            intersec = ray.intersection(Spheres[it]);

            int dist = intersec.distance(ray.origin);
            if (dist < distance)
                nearest = &Spheres[it], distance = dist;
        }

        if (!nearest)
            return BG_COLOR;
        Vector normal = ray.c_normal(*nearest, intersec);
        sf::Color surface_color;

        //bool inside = false;
        if ((nearest->transparence > 0 || nearest->reflectance > 0) && depth > 0)
        {
            double hitangle = -ray.direction.dot(normal);

            Vector reflecdir = ray.direction - normal * 2 * (ray.direction.dot(normal));
            reflecdir.normalize();
            Ray reflection(intersec, reflecdir);
            sf::Color reflecolor = ray_trace1(reflection, Spheres, depth - 1);

            // TO-DO : need to add refraction effect ..

            surface_color = reflecolor * nearest->color;
        }
        else
        {
            //TO-DO : créer des rayons dans x directions pour calculer la couleur par diffusion
        }

        return surface_color + nearest->emissionColor;
    }
}