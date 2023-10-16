cmake_minimum_required(VERSION 3.20)

project(system_fonts)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(README.md src/system_fonts.cpp)
target_type(CONSOLE_APPLICATION)
