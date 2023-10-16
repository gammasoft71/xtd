cmake_minimum_required(VERSION 3.20)

project(save_file_box)
find_package(xtd REQUIRED)
add_sources(README.md src/save_file_box.cpp)
target_type(GUI_APPLICATION)
