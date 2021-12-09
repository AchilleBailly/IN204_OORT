#pragma once

#include "Matrix.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Vector.hpp"
#include <cmath>
#include <functional>
#include <ostream>
#include <vector>

class Camera {

  double distance_to_screen;
  double width;
  double height;
  Vector position;
  Vector orientation;
  unsigned width_p;
  unsigned height_p;
  double fov;
  double aspect_ratio;
  double pixel_size;
  const Vector useful = position - distance_to_screen * orientation;

public:
  Matrix P;

  Camera(Vector Position, Vector Orientation, double FOV, unsigned Width_p,
         unsigned Height_p, double Distance_to_screen)
      : distance_to_screen(Distance_to_screen), position(Position),
        orientation(Orientation), width_p(Width_p), height_p(Height_p),
        fov(FOV * acos(-1) / (double)180) {
    orientation.normalize();
    aspect_ratio = width_p / (double)height_p;

    width = tan(fov / 2) * distance_to_screen;
    height = width / aspect_ratio;
    pixel_size = (double)height / height_p;

    Vector tmp{-orientation.y, orientation.x, 0};
    tmp.normalize();
    Vector tmp2 = orientation.vectoriel(tmp);
    P.set(tmp, orientation, tmp2);
  }

  std::vector<Vector>
  render(std::function<Vector(Ray, std::vector<Sphere>, int)> raytracer,
         std::vector<Sphere> Spheres, int depth) {
    std::vector<Vector> res(width * height);

    for (int i = 0; i < height_p; i++) {
    }

    return res;
  }

  Vector get_dir(const int &i, const int &j) {
    Vector p_position_rel(((double)j - (double)width_p / 2 + 0.5) * pixel_size,
                          ((double)i - (double)height_p / 2 + 0.5) * pixel_size,
                          0);
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