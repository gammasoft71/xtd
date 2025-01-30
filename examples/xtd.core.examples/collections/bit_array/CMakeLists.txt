cmake_minimum_required(VERSION 3.20)

project(bit_array)
find_package(xtd REQUIRED)
add_sources(README.md src/bit_array.cpp)
target_type(CONSOLE_APPLICATION)
