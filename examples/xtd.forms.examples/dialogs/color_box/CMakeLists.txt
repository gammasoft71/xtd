cmake_minimum_required(VERSION 3.3)

project(color_box)
find_package(xtd REQUIRED)
add_sources(src/color_box.cpp)
target_type(GUI_APPLICATION)
