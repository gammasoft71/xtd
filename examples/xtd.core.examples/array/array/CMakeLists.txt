cmake_minimum_required(VERSION 3.20)

project(array)
find_package(xtd REQUIRED)
add_sources(README.md src/array.cpp)
target_type(CONSOLE_APPLICATION)
