#include "Camera.hpp"
#include "Engine.hpp"
#include "Representation.hpp"
#include "Sphere.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <vector>

std::string ressources_path =
    "/Users/achille/Documents/Cours2A/IN204/IN204_OORT/resources";

int main() {
  // load_from_json(ressources_path + "/test_object.json");

  Camera test_cam({0, 0, 0}, {1, 0, 0}, 90, 800, 600, 1);
  Vector test = test_cam.get_dir(300, 400);
  std::cout << test_cam << "\n";

  std::cout << test << "\n";
  std::cout << (test_cam.P) << "\n";

  return 0;
}
