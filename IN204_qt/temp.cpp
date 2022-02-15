#include "temp.hpp"
#include "Camera.hpp"
#include "Engine.hpp"
#include "Materials.hpp"
#include "Materials/Diffuse_create.hpp"
#include "Materials/TestMaterial.hpp"
#include "Object3D.hpp"
#include "Object3D_list.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"
#include "TimeMeasure.hpp"
#include "Vector.hpp"
#include "utils.hpp"
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
  shared_ptr<Transparent> glass =
      make_shared<Transparent>(1.5, 0.05, Vector(0.15, 0.2, 0.1));
  shared_ptr<Diffuse> red = make_shared<Diffuse>(Vector(0.8, 0.1, 0.1));
  shared_ptr<Metal> metal = make_shared<Metal>(Vector(0.8, 0.6, 0.2), 0.0);
  shared_ptr<LightSource> light = make_shared<LightSource>(Vector(3, 3, 3));

  Object3D_list objs;
  objs.add(make_shared<Sphere>(2, Vector(-2, 0, -20), glass));
  // objs.add(make_shared<Sphere>(2, Vector(-2, 1, -14), glass));
  // objs.add(make_shared<Sphere>(10000, Vector(0, -10002, -20), metal));
  objs.add(make_shared<Plane>(Vector(0, -2, 0), Vector(0, 1, 0), red));
  //  objs.add(make_shared<Sphere>(2, Vector(4, 0, -20), metal));
  //  objs.add(make_shared<Sphere>(2, Vector(2, 0, -24), metal));
  objs.add(make_shared<Sphere>(2, Vector(2, 0, -20), red));
  objs.add(make_shared<Sphere>(2, Vector(0, 6, -20), light));

  return objs;
}

Object3D_list scene2() {
  shared_ptr<Transparent> glass =
      make_shared<Transparent>(1.5, 0.05, Vector(0.2, 0.2, 0.1));
  shared_ptr<TestMaterial> red =
      make_shared<TestMaterial>(Vector(0.8, 0.1, 0.1));
  shared_ptr<Metal> metal = make_shared<Metal>(Vector(0.8, 0.6, 0.2), 0.05);
  shared_ptr<LightSource> light = make_shared<LightSource>(Vector(3, 3, 3));

  Object3D_list objs;
  objs.add(make_shared<Sphere>(2, Vector(-2, 0, -20), glass));
  objs.add(make_shared<Sphere>(2, Vector(-2, 1, -14), glass));
  objs.add(make_shared<Sphere>(10000, Vector(0, -10004, -20), red));
  objs.add(make_shared<Sphere>(2, Vector(2, 0, -24), metal));
  objs.add(make_shared<Sphere>(2, Vector(0, 6, -20), light));

  return objs;
}

std::string ressources_path =
    "/Users/achille/Documents/Cours2A/IN204/IN204_OORT/resources";

int temp() {
  // load_from_json(ressources_path + "/test_object.json");
  // position, oriention, fov (degrees), width in pixels, height in pixels,
  // distance camera to screen
  Camera test_cam({0, 0, 0}, {0, 0, -1}, 60, 600, 450);
  test_cam.set_number_samples(1000);

  Object3D_list objs = scene1();

  Engines engines;
  TimeMeasuring t1, t2;
  std::vector<Vector> result;
  t1.setStart();
  // result =
  //     test_cam.render_tbb(engines.ray_trace3, objs, 10);
  t1.setEnd();
  t2.setStart();
  result = test_cam.render(engines.ray_trace3, objs, 5);
  t2.setEnd();

  std::cout << "Temps pour omp : " << t2.getAverageDuration().count() << "\n";
  std::cout << "Temps pour tbb : " << t1.getAverageDuration().count() << "\n";

  save_vector("test_image", result, 600, 450);
  return 0;
}
