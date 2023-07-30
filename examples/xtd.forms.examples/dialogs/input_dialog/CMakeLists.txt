cmake_minimum_required(VERSION 3.5)

project(input_dialog)
find_package(xtd REQUIRED)
add_sources(README.md src/input_dialog.cpp)
target_type(GUI_APPLICATION)
