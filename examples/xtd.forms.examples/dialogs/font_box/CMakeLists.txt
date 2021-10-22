cmake_minimum_required(VERSION 3.3)

project(font_box)
find_package(xtd REQUIRED)
add_sources(src/font_box.cpp)
target_type(GUI_APPLICATION)
