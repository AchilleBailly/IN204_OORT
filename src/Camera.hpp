#pragma once

#include "Matrix.hpp"
#include "Object3D_list.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Vector.hpp"
#include <cmath>
#include <functional>
#include <ostream>
#include <vector>

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
        fov(FOV * acos(-1) / (double)180) {
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

  // rendering function, calls the raytracer algo
  // arguments in order : raytracing function, vector of the spheres in the
  // scene, depth
  std::vector<Vector>
  render(std::function<Vector(const Ray &, const Object3D_list &, const int &)>
             raytracer,
         const Object3D_list &objs, const int &depth) {
    std::vector<Vector> res(width_p * height_p);

    for (int i = 0; i < height_p; i++) {
      for (int j = 0; j < width_p; j++) {
        Ray ray(useful, (*this).get_dir(i, j));
        res.at(j + i * width_p) = raytracer(ray, objs, depth);
      }
    }

    return res;
  }

  // from the coordinates of the pixels, return the direction of the ray going
  // through that pixel arguments : index of the line, index of the column
  Vector get_dir(const int &i, const int &j) {
    Vector p_position_rel(((j + 0.5) * pixel_size - width / 2),
                          ((i + 0.5) * pixel_size - height / 2), 0);
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