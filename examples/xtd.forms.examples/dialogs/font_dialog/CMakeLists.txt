cmake_minimum_required(VERSION 3.20)

project(font_dialog)
find_package(xtd REQUIRED)
add_sources(src/font_dialog.cpp)
target_type(GUI_APPLICATION)
