cmake_minimum_required(VERSION 3.20)

project(hello_world_paint)
find_package(xtd REQUIRED)
add_sources(README.md src/hello_world_paint.cpp)
target_type(GUI_APPLICATION)
