#pragma once
#include "Hit_record.hpp"
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


