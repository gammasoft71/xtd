cmake_minimum_required(VERSION 3.3)

project(sixteen_segment_display)
find_package(xtd REQUIRED)
add_sources(src/sixteen_segment_display.cpp)
target_type(GUI_APPLICATION)
