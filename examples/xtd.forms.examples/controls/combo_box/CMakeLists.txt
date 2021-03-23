cmake_minimum_required(VERSION 3.3)

project(combo_box)
find_package(xtd REQUIRED)
add_sources(src/combo_box.cpp)
target_type(GUI_APPLICATION)
