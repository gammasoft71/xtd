cmake_minimum_required(VERSION 3.20)

project(enumerable_sequence_equal)
find_package(xtd REQUIRED)
add_sources(README.md src/enumerable_sequence_equal.cpp)
target_type(CONSOLE_APPLICATION)
