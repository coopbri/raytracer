#ifndef CAMERA_H
#define CAMERA_H

#include "rtweekend.h"

class camera {
   public:
    camera(vec3 look_from, vec3 look_at, vec3 view_up,
           double vfov,   // top to bottom in degrees
           double aspect  // aspect ratio
    ) {
        origin = look_from;

        auto theta = degrees_to_radians(vfov);
        auto half_height = tan(theta / 2);
        auto half_width = aspect * half_height;

        vec3 w = unit_vector(look_from - look_at);
        vec3 u = unit_vector(cross(view_up, w));
        vec3 v = cross(w, u);

        lower_left_corner = origin - half_width * u - half_height * v - w;

        horizontal = 2 * half_width * u;
        vertical = 2 * half_height * v;
    }

    ray get_ray(double u, double v) {
        return ray(origin,
                   lower_left_corner + u * horizontal + v * vertical - origin);
    }

   public:
    vec3 origin;
    vec3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
};

#endif