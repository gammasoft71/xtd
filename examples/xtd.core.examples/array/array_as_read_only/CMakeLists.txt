cmake_minimum_required(VERSION 3.20)

project(array_as_read_only)
find_package(xtd REQUIRED)
add_sources(README.md src/array_as_read_only.cpp)
target_type(CONSOLE_APPLICATION)
