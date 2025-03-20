#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
public:
  sphere(const point3 &center, double radius)
      : center(center), radius(std::fmax(0, radius)) {}
  bool hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) {
    vec3 oc = center - r.origin();
    //   auto a = dot(r.direction(), r.direction());
    //   auto b = -2.0 * dot(r.direction(), oc);
    //   auto c = dot(oc, oc) - radius * radius;
    //   auto discriminat = b * b - 4 * a * c;
    auto a = r.direction().length_squared();
    auto h = dot(r.direction(), oc);
    auto c = oc.length_squared() - radius * radius;
    auto discriminant = h * h - a * c;
    if (discriminant < 0) {
      return false;
    }
    auto sqrtd = std::sqrt(discriminant);
    auto root= (h - sqrtd) / a;
    if (root <= ray_tmin || root >= ray_tmax) {
      root = (h + sqrtd) / a;
      if (root <= ray_tmin || root >= ray_tmax)
        return false;
    }
    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    return true;
  }

private:
  point3 center;
  double radius;
};

#endif // SPHERE_H
