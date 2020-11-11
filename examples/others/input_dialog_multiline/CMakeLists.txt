cmake_minimum_required(VERSION 3.3)

project(input_dialog_multiline)
find_package(xtd.forms REQUIRED)
add_sources(src/input_dialog_multiline.cpp)
target_type(GUI_APPLICATION)
