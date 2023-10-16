cmake_minimum_required(VERSION 3.20)

project(hello_world_cmake)
find_package(xtd REQUIRED)

message(STATUS "Hello, World!\n")

add_sources(README.md src/hello_world_cmake.cpp)
target_type(GUI_APPLICATION)
