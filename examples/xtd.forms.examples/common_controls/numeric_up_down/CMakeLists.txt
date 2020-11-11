cmake_minimum_required(VERSION 3.3)

project(numeric_up_down)
find_package(xtd REQUIRED)
add_sources(src/numeric_up_down.cpp)
target_type(GUI_APPLICATION)
