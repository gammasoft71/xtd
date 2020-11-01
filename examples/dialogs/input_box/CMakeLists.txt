cmake_minimum_required(VERSION 3.3)

project(input_box)
find_package(xtd.forms REQUIRED)
add_sources(src/input_box.cpp)
target_type(GUI_APPLICATION)
