cmake_minimum_required(VERSION 3.20)

project(form_colors)
find_package(xtd REQUIRED)
add_sources(README.md src/color_chooser.hpp src/color_editor.hpp src/form_colors.cpp)
target_type(GUI_APPLICATION)
