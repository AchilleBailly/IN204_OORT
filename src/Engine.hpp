#pragma once

#include "Ray.hpp"
#include "Representation.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "Vector.hpp"
#include "json.hpp"
#include <algorithm>
#include <cmath>
#include <vector>

namespace {
const Vector BG_COLOR{255, 255, 255};

inline Vector ray_trace1(const Ray &ray, const std::vector<Sphere> &Spheres,
                         const int &depth) {
  float distance = INFINITY;
  const Sphere *nearest = NULL;
  Vector intersec;

  // get the nearest intersection point, if it exists
  for (int it = 0; it < Spheres.size(); it++) {
    intersec = ray.intersection(Spheres[it]);

    int dist = intersec.distance(ray.origin);
    if (dist < distance)
      nearest = &Spheres[it], distance = dist;
  }

  if (!nearest)
    return BG_COLOR;
  Vector normal = ray.c_normal(*nearest, intersec);
  Vector surface_color;

  // bool inside = false;
  if ((nearest->transparence > 0 || nearest->reflectance > 0) && depth > 0) {
    double hitangle = -ray.direction.dot(normal);

    Vector reflecdir = ray.direction - normal * 2 * (ray.direction.dot(normal));
    reflecdir.normalize();
    Ray reflection(intersec, reflecdir);
    Vector reflecolor = ray_trace1(reflection, Spheres, depth - 1);

    // TO-DO : need to add refraction effect ..

    surface_color = reflecolor * nearest->color;
  } else {
    for (unsigned i = 0; i < Spheres.size(); ++i) {
      if (Spheres[i].emissionColor.x > 0) {
        // this is a light
        Vector transmission(1, 0, 0);
        Vector lightDirection = Spheres[i].position - intersec;
        lightDirection.normalize();
        for (unsigned j = 0; j < Spheres.size(); ++j) {
          if (i != j) {
            intersec = ray.intersection(Spheres[i]);

            int dist = intersec.distance(ray.origin);
            if (dist < distance) {
              transmission.x = 0;
              break;
            }
          }
        }
        surface_color += nearest->color * transmission *
                         fmax(float(0), normal.dot(lightDirection)) *
                         Spheres[i].emissionColor;
      }
    }
  }

  return surface_color + nearest->emissionColor;
}
} // namespace