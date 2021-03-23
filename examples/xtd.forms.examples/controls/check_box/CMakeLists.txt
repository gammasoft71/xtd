cmake_minimum_required(VERSION 3.3)

project(check_box)
find_package(xtd REQUIRED)
add_sources(src/check_box.cpp)
target_type(GUI_APPLICATION)
