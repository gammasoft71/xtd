cmake_minimum_required(VERSION 3.20)

project(fill_rectangle)
find_package(xtd REQUIRED)
add_sources(README.md src/fill_rectangle.cpp)
target_type(GUI_APPLICATION)
