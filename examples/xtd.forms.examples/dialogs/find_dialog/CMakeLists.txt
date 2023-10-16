cmake_minimum_required(VERSION 3.20)

project(find_dialog)
find_package(xtd REQUIRED)
add_sources(README.md src/find_dialog.cpp)
target_type(GUI_APPLICATION)
