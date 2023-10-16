cmake_minimum_required(VERSION 3.20)

project(picture_box)
find_package(xtd REQUIRED)
add_sources(README.md src/picture_box.cpp)
target_type(GUI_APPLICATION)
