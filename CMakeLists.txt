cmake_minimum_required(VERSION 3.10)
project(Tracer)

set ( CMAKE_CXX_STANDARD 17 )

set(HEADERFILES
	vec3.h
	ray.h
)

add_executable(Tracer main.cpp ${HEADERFILES})
