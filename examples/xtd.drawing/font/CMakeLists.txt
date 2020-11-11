cmake_minimum_required(VERSION 3.3)

project(font)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(font.cpp)
target_type(CONSOLE_APPLICATION)
