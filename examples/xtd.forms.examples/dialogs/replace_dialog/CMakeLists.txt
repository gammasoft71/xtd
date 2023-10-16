cmake_minimum_required(VERSION 3.20)

project(replace_dialog)
find_package(xtd REQUIRED)
add_sources(README.md src/replace_dialog.cpp)
target_type(GUI_APPLICATION)
