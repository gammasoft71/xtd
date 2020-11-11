cmake_minimum_required(VERSION 3.3)

project(image)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(image.cpp)
target_type(CONSOLE_APPLICATION)
