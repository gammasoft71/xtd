cmake_minimum_required(VERSION 3.20)

project(draw_point)
find_package(xtd REQUIRED)
add_sources(README.md src/draw_point.cpp)
target_type(GUI_APPLICATION)
