cmake_minimum_required(VERSION 3.20)

project(check_box_appearance)
find_package(xtd REQUIRED)
add_sources(src/check_box_appearance.cpp)
target_type(GUI_APPLICATION)
