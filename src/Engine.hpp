#pragma once

#include "Material.hpp"
#include "Object3D.hpp"
#include "Object3D_list.hpp"
#include "Sphere.hpp"
#include <algorithm>
#include <cmath>
#include <memory>
#include <vector>

struct Engines {
  static double mix(const double &a, const double &b, const double &mix) {
    return b * mix + a * (1 - mix);
  }

  // static Vector ray_trace1(const Ray &ray, const Object3D_list &objs,
  //                          const int &depth) {
  //   const Vector BG_COLOR{1, 1, 1};
  //   double bias = 1e-4;

  //   if (depth <= 0)
  //     return Vector(0, 0, 0);

  //   Hit_record hit_record;

  //   // get the obj_hit intersection point, if it exists
  //   if (objs.intersection(ray, bias, INFINITY, hit_record)) {
  //     hit_record.obj_hit->update_hit(ray, hit_record);
  //     Vector surface_color(0);

  //     Vector normal = hit_record.normal;
  //     Vector intersec = hit_record.hit_point;

  //     bool inside = false;
  //     if (ray.direction.dot(normal) > 0) {
  //       normal = -normal;
  //       inside = true;
  //     }
  //     if ((hit_record.obj_hit->transparence > 0 ||
  //          hit_record.obj_hit->reflectance > 0) &&
  //         depth > 0) {
  //       double hitangle = -ray.direction.dot(normal);

  //       double fresneleffect = mix(pow(1 - hitangle, 3), 1, 0.2);

  //       Vector reflecdir = ray.direction + normal * 2 * hitangle;
  //       Ray reflection(intersec, reflecdir);
  //       Vector reflecolor = ray_trace1(reflection, objs, depth - 1);
  //       Vector refraction_color(0);

  //       if (hit_record.obj_hit->transparence) {
  //         double eta = (!inside) ? hit_record.obj_hit->indice_refraction
  //                                : 1 / hit_record.obj_hit->indice_refraction;
  //         // double cosi = hitangle;
  //         // double k = 1 - eta * eta * (1 - cosi * cosi);
  //         // Ray refraction(intersec - normal * bias,
  //         //                ray.direction * eta + normal * (eta * cosi -
  //         //                sqrt(k)));
  //         double cos_theta = std::min(hitangle, 1.0);
  //         double sin_theta = sqrt(1 - cos_theta * cos_theta) * eta;
  //         Ray refraction;
  //         if (sin_theta <= 1) { // refrated
  //           Vector perp = eta * (ray.direction + cos_theta * normal);
  //           Vector parallel = -sqrt(abs(1 - perp.norm2())) * normal;
  //           Ray refraction(intersec - bias * normal, perp + parallel);
  //         } else { // total reflection
  //           Ray refraction(intersec + bias * normal,
  //                          ray.direction - normal * 2 * hitangle);
  //         }
  //         refraction_color = ray_trace1(refraction, objs, depth - 1);
  //         std::cout << refraction_color << "\n";

  //         // std::cout << refraction << "\n" << ray << "\n";
  //       }

  //       surface_color = (reflecolor * fresneleffect +
  //                        refraction_color * (1 - fresneleffect) *
  //                            hit_record.obj_hit->transparence) *
  //                       hit_record.obj_hit->color;
  //     } else {
  //       for (const auto &light : objs.objects) {
  //         if (light->emissionColor.x > 0) {
  //           // this is a light
  //           Vector transmission(1);
  //           Hit_record light_hit;
  //           Vector lightDirection = light->position - intersec;
  //           lightDirection.normalize();
  //           Ray lightray(intersec, lightDirection);
  //           for (const auto &object : objs.objects) {
  //             if (light != object) {
  //               if (object->intersection(lightray, 0 + bias, INFINITY,
  //                                        light_hit))
  //                 transmission = 0;
  //             }
  //           }
  //           surface_color += hit_record.obj_hit->color * transmission *
  //                            std::max(double(0), normal.dot(lightDirection))
  //                            * light->emissionColor;
  //         }
  //       }
  //       // surface_color = hit_record.obj_hit->color;
  //     }

  //   return surface_color + hit_record.obj_hit->emissionColor;
  // } double t = 0.5 * (ray.direction.y + 1.0);
  // return (1 - t) * Vector(1, 1, 1) + t * Vector(0.5, 0.7, 1.0);
  // // return Vector(2);
  // }

  static Vector ray_trace2(const Ray &ray, const Object3D_list &objs,
                           const int &depth) {
    Hit_record hit_record;

    // get the obj_hit intersection point, if it exists
    if (objs.intersection(ray, 0, INFINITY, hit_record)) {
      hit_record.obj_hit->update_hit(ray, hit_record);
      Vector surface_color(0);

      Vector normal = hit_record.normal;
      std::cout << "Normal to hit point : " << normal << "\n";
      Vector intersec = hit_record.hit_point;

      return 0.5 * Vector(normal.x + 1, normal.y + 1, normal.z + 1);
    }
    double t = 0.5 * (ray.direction.y + 1.0);
    return (1 - t) * Vector(1, 1, 1) + t * Vector(0.5, 0.7, 1.0);
  }

  static Vector ray_trace3(const Ray &ray, const Object3D_list &objs,
                           int depth) {
    if (depth == 0) {
      return Vector(0, 0, 0);
    }

    Hit_record hit;
    if (objs.intersection(ray, 1e-4, infinity, hit)) {
      hit.obj_hit->update_hit(ray, hit);
      Vector surface_color(0);
      shared_ptr<Material> mat = hit.obj_hit->material;

      std::vector<Ray> ray_list;

      if (hit.obj_hit->material->scatter(ray, hit, ray_list))
        for (const auto &scattered_ray : ray_list) {
          Vector color = ray_trace3(scattered_ray, objs, depth - 1);
          surface_color += scattered_ray.attenuation * color;
        }
      else
        return hit.color;

      return surface_color;
    }

    double t = 0.5 * (ray.direction.y + 1.0);
    return (1 - t) * Vector(1, 1, 1) + t * Vector(0.5, 0.7, 1.0);
  }
};