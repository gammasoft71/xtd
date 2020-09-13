cmake_minimum_required(VERSION 3.3)

project(font_families)
find_package(xtd.forms REQUIRED)
add_sources(src/font_families.cpp)
target_type(GUI_APPLICATION)
