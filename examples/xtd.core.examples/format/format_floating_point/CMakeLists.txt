cmake_minimum_required(VERSION 3.20)

project(format_floating_point)
find_package(xtd REQUIRED)
add_sources(README.md src/format_floating_point.cpp)
target_type(CONSOLE_APPLICATION)
