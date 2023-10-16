cmake_minimum_required(VERSION 3.20)

project(fill_ellipse)
find_package(xtd REQUIRED)
add_sources(README.md src/fill_ellipse.cpp)
target_type(GUI_APPLICATION)
