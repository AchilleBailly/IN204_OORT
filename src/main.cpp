#include "Camera.hpp"
#include "Dielectric.hpp"
#include "Engine.hpp"
#include "Metal.hpp"
#include "Object3D_list.hpp"
#include "Sphere.hpp"
#include "TestMaterial.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

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

Object3D_list scene1() {
  shared_ptr<Transparent> glass = make_shared<Transparent>(1.5, 0.05);
  shared_ptr<TestMaterial> red = make_shared<TestMaterial>(Vector(1, 0, 0));
  shared_ptr<Metal> metal = make_shared<Metal>(Vector(0.8, 0.6, 0.2), 1);

  Object3D_list objs;
  objs.add(make_shared<Sphere>(2, Vector(0, 0, -20), glass));
  // objs.add(make_shared<Sphere>(10000, Vector(0, -10004, -20), red));
  objs.add(make_shared<Sphere>(2, Vector(4, 0, -20), metal));
  objs.add(make_shared<Sphere>(2, Vector(2, 0, -24), metal));

  return objs;
}

std::string ressources_path =
    "/Users/achille/Documents/Cours2A/IN204/IN204_OORT/resources";

int main() {
  // Spheres.add(make_shared<Sphere>(1, Vector(1, 0, 0), Vector(0, 0, -4), 0, 0,
  // 1,
  //                                 Vector(0, 1, 0)));
  // Spheres.add(make_shared<Sphere>(10000, Vector(0.2, 0.2, 0.2),
  //                                 Vector(0, -10004, -20), 1, 0));
  // Spheres.add(
  //     make_shared<Sphere>(2, Vector(1, 0.32, 0.36), Vector(0, 0, -20), 0,
  //     1));
  // Spheres.add(make_shared<Sphere>(3, Vector(0.9, 0.76, 0.46),
  //                                 Vector(5, -1, -15), 0, 1));

  // Spheres.add(make_shared<Sphere>(3, Vector(0, 0, 0), Vector(0, 20, -30), 0,
  // 0,
  //                                 1, Vector(3, 3, 3)));
  // load_from_json(ressources_path + "/test_object.json");
  // position, oriention, fov (degrees), width in pixels, height in pixels,
  // distance camera to screen
  Camera test_cam({0, 0, 0}, {0, 0, -1}, 60, 800, 600);

  Object3D_list objs = scene1();

  Engines engines;
  std::vector<Vector> result = test_cam.render(engines.ray_trace3, objs, 10);
  save_vector("test_image", result, 800, 600);
  return 0;
}
