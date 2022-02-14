#pragma once

#include "Matrix.hpp"
#include "Object3D_list.hpp"
#include "Sphere.hpp"
#include "utils.hpp"
#include <functional>
#include <omp.h>
#include <ostream>
#include <tbb/tbb.h>

class Camera {

  const double distance_to_screen;
  double width;
  double height;
  Vector position;
  Vector orientation;
  unsigned width_p;
  unsigned height_p;
  double fov;
  double aspect_ratio;
  double pixel_size;
  int nb_samples = 1;

public:
  Matrix P;
  const Vector useful = position - distance_to_screen * orientation;

  // Constructor arguments in order : position, oriention, fov (degrees), width
  // in pixels, height in pixels,
  //  distance camera to screen
  Camera(Vector Position, Vector Orientation, double FOV, unsigned Width_p,
         unsigned Height_p, double Distance_to_screen = 1)
      : distance_to_screen(Distance_to_screen), position(Position),
        orientation(Orientation), width_p(Width_p), height_p(Height_p),
        fov(degrees_to_radians(FOV)) {
    orientation.normalize();

    aspect_ratio = width_p / (double)height_p;
    width = tan(fov / 2) * distance_to_screen;
    height = width / aspect_ratio;
    pixel_size = (double)height / height_p;

    Vector tmp{-orientation.z, 0, orientation.x};
    tmp.normalize();
    Vector tmp2 = orientation.vectoriel(tmp);
    P.set(tmp, tmp2, orientation);
  }

  void set_number_samples(int n) { nb_samples = n; }

  int get_number_samples() { return nb_samples; }

  // rendering function, calls the raytracer algo
  // arguments in order : raytracing function, vector of the spheres in the
  // scene, depth
  std::vector<Vector>
  render(std::function<Vector(const Ray &, const Object3D_list &, const int &)>
             raytracer,
         const Object3D_list &objs, const int &depth) {
    std::vector<Vector> res(width_p * height_p);

#pragma omp parallel for num_threads(16)
    for (int i = 0; i < height_p * width_p; i++) {
      // if (i == 0) {
      //   std::cout << omp_get_num_threads() << "\n";
      // }
      // std::cout << "(" << i << "/" << height_p * width_p << ")";
      // std::cout << "\n";
      for (int k = 0; k < nb_samples; k++) {
        Ray ray(useful, (*this).get_dir_rand(i / width_p, i % width_p));
        res.at(i) += raytracer(ray, objs, depth);
      }
      res.at(i) /= nb_samples;
      res.at(i) = pow(res.at(i), 1. / 2.);
    }

    return res;
  }

  std::vector<Vector> render_tbb(
      std::function<Vector(const Ray &, const Object3D_list &, const int &)>
          raytracer,
      const Object3D_list &objs, const int &depth) {
    std::vector<Vector> res(width_p * height_p);
    // auto partitioner = tbb::simple_partitioner();
    auto partitioner = tbb::auto_partitioner();
    tbb::parallel_for(
        tbb::blocked_range2d<unsigned, unsigned>(0, width_p, 4, 0, height_p, 4),
        [&](tbb::blocked_range2d<unsigned, unsigned> const &r) {
          // int thread_limit = oneapi::tbb::global_control::active_value(
          //     oneapi::tbb::global_control::max_allowed_parallelism);
          // assert(thread_limit == MAX_NUM_THREADS);
          //  On parcourt les pixels du sous-block de l'image dans l'espace
          //  image :
          for (auto i = r.cols().begin(); i < r.cols().end(); ++i) {
            for (auto j = r.rows().begin(); j < r.rows().end(); ++j) {
              for (int k = 0; k < nb_samples; k++) {
                Ray ray(useful, (*this).get_dir_rand(i, j));
                res.at(j + i * width_p) += raytracer(ray, objs, depth);
              }
              res.at(j + i * width_p) /= nb_samples;
              res.at(j + i * width_p) = pow(res.at(j + i * width_p), 1. / 2.);
            }
          }
        },
        partitioner);
    return res;
  }

  // from the coordinates of the pixels, return the direction of the ray going
  // through that pixel
  // arguments : index of the line, index of the column
  Vector get_dir(const int &i, const int &j) {
    Vector p_position_rel(((j + 0.5) * pixel_size - width / 2),
                          ((i + 0.5) * pixel_size - height / 2), 0);
    Vector dir = P * p_position_rel - useful;
    return dir;
  }

  // from the coordinates of the pixels, return the direction of the ray going
  // through that pixel with some randomness
  // arguments : index of the line, index of the column
  Vector get_dir_rand(const int &i, const int &j) {
    double di = random_double(0, 1);
    double dj = random_double(0, 1);
    Vector p_position_rel(((j + di) * pixel_size - width / 2),
                          ((i + dj) * pixel_size - height / 2), 0);
    Vector dir = P * p_position_rel - useful;
    return dir;
  }

  friend std::ostream &operator<<(std::ostream &os, const Camera &cam) {
    os << "Position : " << cam.position << std::endl;
    os << "Orientation : " << cam.orientation << std::endl;
    os << "Width pixels : " << cam.width_p << std::endl;
    os << "Height pixels : " << cam.height_p << std::endl;
    os << "Aspect ratio : " << cam.aspect_ratio << std::endl;
    os << "FOV : " << cam.fov * 180 / acos(-1) << std::endl;
    os << "Virtual height : " << cam.height << std::endl;
    os << "Virtual width : " << cam.width << std::endl;
    os << "Pixel size : " << cam.pixel_size << std::endl;
    return os;
  }
};