# Raytracer
This project was created to develop familiarity with ray tracing techniques in computer graphics, primarily using https://raytracing.github.io/ and https://pbrt.org/ as resources. Initially (and currently) it almost completely models Peter Shirley's Ray Tracing tutorial books, though over time I am planning on expanding it, modernizing it (with C++ features such as modules and `constexpr`), and turning it into a library.

# Building and Running
This project uses CMake. To build an executable on Unix-based systems (macOS, Linux), run the following commands:
```
mkdir build
cd build
cmake ..
make
```
To run the program, specify an output `ppm` file as below:
```
./Tracer > output.ppm
```
