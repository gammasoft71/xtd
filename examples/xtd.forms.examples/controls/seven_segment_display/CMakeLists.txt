cmake_minimum_required(VERSION 3.3)

project(seven_segment_display)
find_package(xtd REQUIRED)
add_sources(src/seven_segment_display.cpp)
target_type(GUI_APPLICATION)
