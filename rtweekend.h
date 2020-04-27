#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <functional>
#include <limits>
#include <memory>
#include <random>

// #include "ray.h"
// #include "vec3.h"

using std::make_shared;
using std::shared_ptr;

// constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// utility functions
inline double degrees_to_radians(double degrees) { return degrees * pi / 180; }
inline double ffmin(double a, double b) { return a <= b ? a : b; }
inline double ffmax(double a, double b) { return a >= b ? a : b; }

// generate a random real number in [0,1)
inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    static std::function<double()> rand_generator =
        std::bind(distribution, generator);
    return rand_generator();
    // return rand() / (RAND_MAX + 1.0);
}

// generate a random real number in [min,max)
inline double random_double(double min, double max) {
    return min + (max - min) * random_double();
}

// clamp `x` to range [min,max]
inline double clamp(double x, double min, double max) {
    // clamped min value
    if (x < min) return min;

    // clamped max value
    if (x > max) return max;

    // return `x` itself if already in range
    return x;
}

#include "ray.h"
#include "vec3.h"

#endif