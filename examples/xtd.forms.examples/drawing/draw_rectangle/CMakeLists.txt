cmake_minimum_required(VERSION 3.5)

project(draw_rectangle)
find_package(xtd REQUIRED)
add_sources(README.md src/draw_rectangle.cpp)
target_type(GUI_APPLICATION)
