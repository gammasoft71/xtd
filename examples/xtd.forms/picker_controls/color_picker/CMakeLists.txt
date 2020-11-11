cmake_minimum_required(VERSION 3.3)

project(color_picker)
find_package(xtd.forms REQUIRED)
add_sources(src/color_picker.cpp)
target_type(GUI_APPLICATION)
