cmake_minimum_required(VERSION 3.20)

project(apple_colors)
find_package(xtd REQUIRED)
add_sources(README.md src/apple_colors.cpp)
target_type(CONSOLE_APPLICATION)
