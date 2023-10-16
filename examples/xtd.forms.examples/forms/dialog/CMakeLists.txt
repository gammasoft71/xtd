cmake_minimum_required(VERSION 3.20)

project(dialog)
find_package(xtd REQUIRED)
add_sources(README.md src/dialog.cpp)
target_type(GUI_APPLICATION)
