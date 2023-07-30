cmake_minimum_required(VERSION 3.5)

project(font_families)
find_package(xtd REQUIRED)
add_sources(README.md src/font_families.cpp)
target_type(GUI_APPLICATION)
