cmake_minimum_required(VERSION 3.3)

project(colors)
find_package(xtd REQUIRED)
add_sources(src/colors.cpp)
target_type(GUI_APPLICATION)
