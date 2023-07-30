cmake_minimum_required(VERSION 3.5)

project(color_picker)
find_package(xtd REQUIRED)
add_sources(README.md src/color_picker.cpp)
target_type(GUI_APPLICATION)
