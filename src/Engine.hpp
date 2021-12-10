#pragma once

#include "Hit_record.hpp"
#include "Object3D_list.hpp"
#include "Ray.hpp"
#include "Representation.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "Sphere.hpp"
#include "Vector.hpp"
#include "json.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Engines {
  static double mix(const double &a, const double &b, const double &mix) {
    return b * mix + a * (1 - mix);
  }

  static Vector ray_trace1(const Ray &ray, const Object3D_list &objs,
                           const int &depth) {
    const Vector BG_COLOR{1, 1, 1};

    Hit_record hit_record;

    // get the obj_hit intersection point, if it exists
    if (objs.intersection(ray, 0, INFINITY, hit_record)) {
      hit_record.obj_hit->update_hit(ray, hit_record);
      Vector surface_color(0);

      Vector normal = hit_record.normal;
      Vector intersec = hit_record.hit_point;

      double bias = 1e-4;
      bool inside = false;
      if (ray.direction.dot(normal) > 0) {
        normal = -normal;
        inside = true;
      }
      if ((hit_record.obj_hit->transparence > 0 ||
           hit_record.obj_hit->reflectance > 0) &&
          depth > 0) {
        std::cout << "Transparent or reflective\n";
        double hitangle = -ray.direction.dot(normal);

        double fresneleffect = mix(pow(1 - hitangle, 3), 1, 0.1);

        Vector reflecdir =
            ray.direction - normal * 2 * (ray.direction.dot(normal));
        Ray reflection(intersec, reflecdir);
        Vector reflecolor = ray_trace1(reflection, objs, depth - 1);
        Vector refraction_color(0);

        if (hit_record.obj_hit->transparence) {
          double eta = (inside) ? hit_record.obj_hit->indice_refraction
                                : 1 / hit_record.obj_hit->indice_refraction;
          double cosi = hitangle;
          double k = 1 - eta * eta * (1 - cosi * cosi);
          Ray refraction(intersec - normal * bias,
                         ray.direction * eta + normal * (eta * cosi - sqrt(k)));
          refraction_color = ray_trace1(refraction, objs, depth - 1);
        }

        surface_color = (reflecolor * fresneleffect +
                         refraction_color * (1 - fresneleffect) *
                             hit_record.obj_hit->transparence) *
                        hit_record.obj_hit->color;
      } else {
        std::cout << "Diffuse\n";
        // for (unsigned i = 0; i < Spheres.size(); ++i) {
        //   if (Spheres[i].emissionColor.x > 0) {
        //     // this is a light
        //     Vector transmission(1);
        //     Vector lightDirection = Spheres[i].position - intersec;
        //     lightDirection.normalize();
        //     for (unsigned j = 0; j < Spheres.size(); ++j) {
        //       if (i != j) {
        //         intersec = ray.intersection(Spheres[i]);

        //         int dist = intersec.distance(ray.origin);
        //         if (dist < distance) {
        //           transmission = 0;
        //           break;
        //         }
        //       }
        //     }
        //     surface_color += hit_record.obj_hit->color * transmission *
        //                      std::max(double(0), normal.dot(lightDirection))
        //                      * Spheres[i].emissionColor;
        //   }
        // }
        surface_color = hit_record.obj_hit->color;
      }

      return surface_color + hit_record.obj_hit->emissionColor;
    }
    double t = 0.5 * (ray.direction.y + 1.0);
    return (1 - t) * Vector(1, 1, 1) + t * Vector(0.5, 0.7, 1.0);
  }
};