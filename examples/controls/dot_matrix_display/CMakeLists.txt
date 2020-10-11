cmake_minimum_required(VERSION 3.3)

project(dot_matrix_display)
find_package(xtd.forms REQUIRED)
add_sources(src/dot_matrix_display.cpp)
target_type(GUI_APPLICATION)
