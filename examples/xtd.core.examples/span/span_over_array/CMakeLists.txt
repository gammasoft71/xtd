cmake_minimum_required(VERSION 3.20)

project(span_over_array)
find_package(xtd REQUIRED)
add_sources(README.md src/span_over_array.cpp)
target_type(CONSOLE_APPLICATION)
