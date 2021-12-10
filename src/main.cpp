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

std::string ressources_path =
    "/Users/achille/Documents/Cours2A/IN204/IN204_OORT/resources";

int main() {
  // load_from_json(ressources_path + "/test_object.json");
  // position, oriention, fov (degrees), width in pixels, height in pixels,
  // distance camera to screen
  Camera test_cam({0, 0, 0}, {0, 0, -1}, 90, 200, 200);
  std::cout << test_cam << "\n";
  std::cout << test_cam.P << "\n";

  Object3D_list Spheres;
  Spheres.add(make_shared<Sphere>(16, Vector(1, 0, 0), Vector(0, 0, -4), 0, 0,
                                  1, Vector(0, 1, 0)));
  //   Spheres.add({
  //       10000,
  //       {0.2, 0.2, 0.2},
  //       {0, -10004, -20},
  //       1,
  //       0,
  //   });
  //   Spheres.add({8, {1, 0.32, 0.36}, {0, 0, -20}, 1, 0.5});
  //   Spheres.add({3, {0.9, 0.76, 0.46}, {5, -1, -15}, 1, 0});

  //   Spheres.add({3, {0, 0, 0}, {0, 20, -30}, 0, 0, 1, {3, 3, 3}});

  Engines engines;
  std::vector<Vector> result = test_cam.render(engines.ray_trace1, Spheres, 1);
  save_vector("test_image", result, 200, 200);
  return 0;
}
