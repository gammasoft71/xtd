cmake_minimum_required(VERSION 3.3)

project(font_picker)
find_package(xtd REQUIRED)
add_sources(src/font_picker.cpp)
target_type(GUI_APPLICATION)
