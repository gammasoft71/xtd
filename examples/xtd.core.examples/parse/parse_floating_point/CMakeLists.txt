cmake_minimum_required(VERSION 3.3)

project(parse_floating_point)
find_package(xtd REQUIRED)
add_sources(README.md src/parse_floating_point.cpp)
target_type(CONSOLE_APPLICATION)
