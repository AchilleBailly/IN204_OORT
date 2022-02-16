#pragma once
#include "Hit_record.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "json.hpp"
#include <sys/types.h>

using std::shared_ptr;

class Object3D_list : public Object3D {
public:
  std::vector<shared_ptr<Object3D>> objects;

  Object3D_list() : objects() {}
  Object3D_list(shared_ptr<Object3D> obj) { add(obj); }
  void add(shared_ptr<Object3D> obj) { objects.push_back(obj); }

  virtual bool intersection(const Ray &ray, const double &t_min,
                            const double &t_max,
                            Hit_record &hit_record) const override;
  virtual void update_hit(const Ray &, Hit_record &) const override {}

  shared_ptr<Object3D> getObjectByLabel(const QString& label){
      for(auto it = objects.begin(); it != objects.end(); it ++){
          if(label == (*it)->label)
               return *it;
      }
      return nullptr;
  }

  virtual json to_json() override {
      std::vector<json> jsonlist;
      for(auto it = objects.begin(); it != objects.end(); it++) {
          jsonlist.push_back((*it)->to_json());
      }
      json out = jsonlist;
      return out;
  }

    void from_json(json input) {
        std::vector<json> list = input.get<std::vector<json>>();
        try {
            for(auto it = list.begin(); it != list.end(); it ++){
                json jobj = (*it);
                std::ofstream out("test.json");
                out << std::setw(4) << jobj << std::endl;
                json jpos = jobj["position"];
                json jmat = jobj["material"];
                shared_ptr<Object3D> obj;
                shared_ptr<Material> mat;
                Vector position = {jpos["x"].get<double>(), jpos["y"].get<double>(), jpos["z"].get<double>()};
                auto label = jobj["label"].get<std::string>();

                // Cases on the type of material
                if(jmat["type"].get<std::string>() == "transparent"){
                    json jabso = jmat["absorption"];
                    Vector absorption = {jabso["x"].get<double>(), jabso["y"].get<double>(), jabso["z"].get<double>()};
                    double ior = jmat["ior"].get<double>();
                    double reflectivity = jmat["reflectivity"].get<double>();
                    mat= make_shared<Transparent>(ior, reflectivity, absorption);
                }
                else if(jmat["type"].get<std::string>() == "diffuse") {
                    json jalbe = jmat["albedo"];
                    Vector albedo = {jalbe["x"].get<double>(), jalbe["y"].get<double>(), jalbe["z"].get<double>()};
                    mat = make_shared<Diffuse>(albedo);
                }
                else if(jmat["type"].get<std::string>() == "metal") {
                    double fuzz = jmat["fuzz"].get<double>();
                    json jalbe = jmat["albedo"];
                    Vector albedo = {jalbe["x"].get<double>(), jalbe["y"].get<double>(), jalbe["z"].get<double>()};
                    mat = make_shared<Metal>(albedo, fuzz);
                }
                else if(jmat["type"].get<std::string>() == "lightsource") {
                    json jalbe = jmat["color"];
                    Vector albedo = {jalbe["x"].get<double>(), jalbe["y"].get<double>(), jalbe["z"].get<double>()};
                    mat = make_shared<LightSource>(albedo);
                }

                // Cases on the type of the object added
                if(jobj["type"].get<std::string>() == "Sphere") {
                    double radius = jobj["radius"].get<double>();
                    obj = make_shared<Sphere>(radius, position, mat);
                }
                else if(jobj["type"].get<std::string>() == "Plane"){
                    json jorient = jobj["orientation"];
                    Vector orientation = {jorient["x"].get<double>(), jorient["y"].get<double>(), jorient["z"].get<double>()};
                    obj = make_shared<Plane>(position, orientation, mat);
                }
                obj.get()->setLabel(QString::fromStdString(label));
                this->add(obj);
            }
        }  catch (const json::exception &e) {
            throw e;
        }
    }

  void load_from_json(std::string file_name) {
    std::fstream input;
    input.open(file_name);
  }
};

inline bool Object3D_list::intersection(const Ray &ray, const double &t_min,
                                        const double &t_max,
                                        Hit_record &hit_record) const {
  Hit_record temp;
  temp.t = t_max;
  hit_record = temp;
  bool res = false;
  for (const auto &obj : objects) {
    if (obj->intersection(ray, t_min, hit_record.t, temp)) {
      res = true;
      temp.obj_hit = obj;
      hit_record = temp;
    }
  }
  return res;
}


