cmake_minimum_required(VERSION 3.5)

project(themes)
find_package(xtd REQUIRED)
add_sources(README.md src/themes.cpp)
target_type(GUI_APPLICATION)
