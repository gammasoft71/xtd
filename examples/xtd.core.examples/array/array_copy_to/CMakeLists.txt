cmake_minimum_required(VERSION 3.20)

project(array_copy_to)
find_package(xtd REQUIRED)
add_sources(README.md src/array_copy_to.cpp)
target_type(CONSOLE_APPLICATION)
