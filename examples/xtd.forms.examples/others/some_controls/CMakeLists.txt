cmake_minimum_required(VERSION 3.3)

project(some_controls)
find_package(xtd REQUIRED)
add_sources(src/some_controls.cpp)
target_type(GUI_APPLICATION)
