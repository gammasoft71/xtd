cmake_minimum_required(VERSION 3.20)

project(input_box)
find_package(xtd REQUIRED)
add_sources(README.md src/input_box.cpp)
target_type(GUI_APPLICATION)
