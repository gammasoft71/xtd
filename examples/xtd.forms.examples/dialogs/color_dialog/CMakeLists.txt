cmake_minimum_required(VERSION 3.3)

project(color_dialog)
find_package(xtd REQUIRED)
add_sources(src/color_dialog.cpp)
target_type(GUI_APPLICATION)
