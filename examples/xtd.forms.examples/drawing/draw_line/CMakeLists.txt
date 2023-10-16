cmake_minimum_required(VERSION 3.20)

project(draw_line)
find_package(xtd REQUIRED)
add_sources(README.md src/draw_line.cpp)
target_type(GUI_APPLICATION)
