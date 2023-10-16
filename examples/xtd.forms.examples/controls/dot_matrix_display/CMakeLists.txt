cmake_minimum_required(VERSION 3.20)

project(dot_matrix_display)
find_package(xtd REQUIRED)
add_sources(README.md src/dot_matrix_display.cpp)
target_type(GUI_APPLICATION)
