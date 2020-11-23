cmake_minimum_required(VERSION 3.3)

project(hello_world_png)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(src/hello_world_png.cpp)
target_type(CONSOLE_APPLICATION)
