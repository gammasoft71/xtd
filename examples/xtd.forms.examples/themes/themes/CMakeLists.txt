cmake_minimum_required(VERSION 3.3)

project(themes)
find_package(xtd REQUIRED)
add_sources(src/themes.cpp)
target_type(GUI_APPLICATION)
