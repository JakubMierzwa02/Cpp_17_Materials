﻿cmake_minimum_required (VERSION 3.8)

project (Cpp_17_Materials)

add_executable (Cpp_17_Materials 
main.cpp 
Vector.h 
Vector.cpp
Complex.h 
Complex.cpp
Container.h
Container.cpp 
Shape.h
Shape.cpp 
Value.h)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Cpp_17_Materials PROPERTY CXX_STANDARD 20)
endif()
