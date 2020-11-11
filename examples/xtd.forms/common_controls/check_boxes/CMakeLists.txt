cmake_minimum_required(VERSION 3.3)

project(check_boxes)
find_package(xtd.forms REQUIRED)
add_sources(src/check_boxes.cpp)
target_type(GUI_APPLICATION)
