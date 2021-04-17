cmake_minimum_required(VERSION 3.3)

project(draw_rectangle)
find_package(xtd REQUIRED)
add_sources(src/draw_rectangle.cpp)
target_type(GUI_APPLICATION)
