cmake_minimum_required(VERSION 3.3)

project(group_box_and_check_box)
find_package(xtd REQUIRED)
add_sources(src/group_box_and_check_box.cpp)
target_type(GUI_APPLICATION)
