cmake_minimum_required(VERSION 3.3)

project(hello_world_paint)
find_package(xtd REQUIRED)
add_sources(src/hello_world_paint.cpp)
target_type(GUI_APPLICATION)
