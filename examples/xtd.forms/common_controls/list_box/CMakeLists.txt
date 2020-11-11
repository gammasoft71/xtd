cmake_minimum_required(VERSION 3.3)

project(list_box)
find_package(xtd REQUIRED)
add_sources(src/list_box.cpp)
target_type(GUI_APPLICATION)
