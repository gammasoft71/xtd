cmake_minimum_required(VERSION 3.20)

project(input_dialog_multiline)
find_package(xtd REQUIRED)
add_sources(README.md src/input_dialog_multiline.cpp)
target_type(GUI_APPLICATION)
