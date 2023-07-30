cmake_minimum_required(VERSION 3.5)

project(draw_ellipse)
find_package(xtd REQUIRED)
add_sources(README.md src/draw_ellipse.cpp)
target_type(GUI_APPLICATION)
