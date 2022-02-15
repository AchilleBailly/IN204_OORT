#ifndef TEMP_HPP
#define TEMP_HPP

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

void save_vector(const std::string &, std::vector<Vector>,
                 size_t, size_t);
void print_vector(std::ostream &, std::vector<Vector> , size_t , size_t );
Object3D_list scene1();
Object3D_list scene2();
int temp();

#endif // TEMP_HPP
