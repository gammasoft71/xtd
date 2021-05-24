cmake_minimum_required(VERSION 3.3)

project(dialog)
find_package(xtd REQUIRED)
add_sources(src/dialog.cpp)
target_type(GUI_APPLICATION)
