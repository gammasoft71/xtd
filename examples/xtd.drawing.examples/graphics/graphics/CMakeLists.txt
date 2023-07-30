cmake_minimum_required(VERSION 3.5)

project(graphics)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(README.md src/graphics.cpp)
target_type(CONSOLE_APPLICATION)
