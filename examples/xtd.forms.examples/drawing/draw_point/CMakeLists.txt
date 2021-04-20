cmake_minimum_required(VERSION 3.3)

project(draw_point)
find_package(xtd REQUIRED)
add_sources(src/draw_point.cpp)
target_type(GUI_APPLICATION)
