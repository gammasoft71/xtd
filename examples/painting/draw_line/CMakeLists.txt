cmake_minimum_required(VERSION 3.3)

project(draw_line)
find_package(xtd.forms REQUIRED)
add_sources(src/draw_line.cpp)
target_type(GUI_APPLICATION)
