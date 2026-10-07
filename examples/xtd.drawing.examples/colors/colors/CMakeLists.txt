cmake_minimum_required(VERSION 3.20)

project(colors)
find_package(xtd REQUIRED)
add_sources(README.md src/colors.cpp)
target_type(CONSOLE_APPLICATION)
