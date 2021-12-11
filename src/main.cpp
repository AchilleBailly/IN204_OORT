#include "Camera.hpp"
#include "Engine.hpp"
#include "Object3D.hpp"
#include "Object3D_list.hpp"
#include "Ray.hpp"
#include "Representation.hpp"
#include "Sphere.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstddef>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

using std::make_shared;

void save_vector(const std::string &file_name, std::vector<Vector> color,
                 size_t width_p, size_t height_p) {
  std::ofstream ofs("./" + file_name + ".ppm",
                    std::ios::out | std::ios::binary);
  ofs << "P6\n" << width_p << " " << height_p << "\n255\n";
  for (unsigned i = 0; i < width_p * height_p; ++i) {
    ofs << (unsigned char)(std::min(double(1), color[i].x) * 255)
        << (unsigned char)(std::min(double(1), color[i].y) * 255)
        << (unsigned char)(std::min(double(1), color[i].z) * 255);
  }
  ofs.close();
}

void print_vector(std::ostream &out, std::vector<Vector> color, size_t width_p,
                  size_t height_p) {
  out << "P3\n" << width_p << ' ' << height_p << "\n255\n";
  for (unsigned i = 0; i < width_p * height_p; ++i) {
    out << static_cast<int>(color[i].x * 255.999) << ' '
        << static_cast<int>(color[i].y * 255.999) << ' '
        << static_cast<int>(color[i].z * 255.999) << "\n";
  }
}

std::string ressources_path =
    "/Users/achille/Documents/Cours2A/IN204/IN204_OORT/resources";

int main() {
  // load_from_json(ressources_path + "/test_object.json");
  // position, oriention, fov (degrees), width in pixels, height in pixels,
  // distance camera to screen
  Camera test_cam({0, 0, 0}, {0, 0, -1}, 60, 200, 200);
  std::cout << test_cam << "\n";
  std::cout << test_cam.P << "\n";

  Object3D_list Spheres;
  // Spheres.add(make_shared<Sphere>(1, Vector(1, 0, 0), Vector(0, 0, -4), 0, 0,
  // 1,
  //                                 Vector(0, 1, 0)));
  // Spheres.add(make_shared<Sphere>(10000, Vector(0.2, 0.2, 0.2),
  //                                 Vector(0, -10004, -20), 1, 0));
  Spheres.add(
      make_shared<Sphere>(2, Vector(1, 0.32, 0.36), Vector(0, 0, -20), 0, 1));
  Spheres.add(make_shared<Sphere>(3, Vector(0.9, 0.76, 0.46),
                                  Vector(5, -1, -15), 0, 1));

  Spheres.add(make_shared<Sphere>(3, Vector(0, 0, 0), Vector(0, 20, -30), 0, 0,
                                  1, Vector(3, 3, 3)));

  Engines engines;
  std::vector<Vector> result = test_cam.render(engines.ray_trace2, Spheres, 5);
  print_vector(std::cout, result, 200, 200);
  save_vector("test_image", result, 200, 200);
  return 0;
}
