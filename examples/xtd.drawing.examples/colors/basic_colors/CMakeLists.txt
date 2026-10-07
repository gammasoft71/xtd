cmake_minimum_required(VERSION 3.20)

project(basic_colors)
find_package(xtd REQUIRED)
add_sources(README.md src/basic_colors.cpp)
target_type(CONSOLE_APPLICATION)
