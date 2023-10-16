cmake_minimum_required(VERSION 3.20)

project(border_style)
find_package(xtd REQUIRED)
add_sources(README.md src/border_style.cpp)
target_type(GUI_APPLICATION)
