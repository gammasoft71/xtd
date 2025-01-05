cmake_minimum_required(VERSION 3.20)

project(enumerable_count_by)
find_package(xtd REQUIRED)
add_sources(README.md src/enumerable_count_by.cpp)
target_type(CONSOLE_APPLICATION)
