cmake_minimum_required(VERSION 3.3)

project(draw_ellipse)
find_package(xtd REQUIRED)
add_sources(src/draw_ellipse.cpp)
target_type(GUI_APPLICATION)
