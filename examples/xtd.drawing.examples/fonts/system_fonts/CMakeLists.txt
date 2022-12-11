cmake_minimum_required(VERSION 3.3)

project(system_fonts)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(system_fonts.cpp)
target_type(CONSOLE_APPLICATION)
