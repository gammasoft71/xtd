cmake_minimum_required(VERSION 3.3)

project(fill_rounded_rectangle)
find_package(xtd REQUIRED)
add_sources(src/fill_rounded_rectangle.cpp)
target_type(GUI_APPLICATION)
