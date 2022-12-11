cmake_minimum_required(VERSION 3.3)

project(point)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(point.cpp)
target_type(CONSOLE_APPLICATION)
