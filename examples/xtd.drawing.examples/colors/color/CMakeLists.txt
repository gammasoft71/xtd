cmake_minimum_required(VERSION 3.3)

project(color)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(color.cpp)
target_type(CONSOLE_APPLICATION)
