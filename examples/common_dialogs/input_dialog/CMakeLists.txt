cmake_minimum_required(VERSION 3.3)

project(input_dialog)
find_package(xtd.forms REQUIRED)
add_sources(src/input_dialog.cpp)
target_type(GUI_APPLICATION)
