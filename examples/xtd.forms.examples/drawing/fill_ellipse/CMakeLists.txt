cmake_minimum_required(VERSION 3.3)

project(fill_ellipse)
find_package(xtd REQUIRED)
add_sources(src/fill_ellipse.cpp)
target_type(GUI_APPLICATION)
