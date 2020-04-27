#ifndef CAMERA_H
#define CAMERA_H

#include "rtweekend.h"

class camera {
   public:
    camera(vec3 look_from, vec3 look_at, vec3 view_up,
           double vfov,      // top to bottom in degrees
           double aspect,    // aspect ratio
           double aperture,  // aperture to control effective lens size
           double focus_dist) {
        origin = look_from;
        lens_radius = aperture / 2;

        auto theta = degrees_to_radians(vfov);
        auto half_height = tan(theta / 2);
        auto half_width = aspect * half_height;

        vec3 w = unit_vector(look_from - look_at);
        vec3 u = unit_vector(cross(view_up, w));
        vec3 v = cross(w, u);

        lower_left_corner = origin - half_width * focus_dist * u -
                            half_height * focus_dist * v - focus_dist * w;

        horizontal = 2 * half_width * focus_dist * u;
        vertical = 2 * half_height * focus_dist * v;
    }

    ray get_ray(double s, double t) {
        vec3 rd = lens_radius * random_in_unit_disk();
        vec3 offset = u * rd.x() + v * rd.y();

        return ray(origin + offset, lower_left_corner + s * horizontal +
                                        t * vertical - origin - offset);
    }

   public:
    vec3 origin;
    vec3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
    vec3 u, v, w;
    double lens_radius;
};

#endif