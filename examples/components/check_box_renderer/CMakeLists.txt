cmake_minimum_required(VERSION 3.3)

project(check_box_renderer)
find_package(xtd.forms REQUIRED)
add_sources(src/check_box_renderer.cpp)
target_type(GUI_APPLICATION)
