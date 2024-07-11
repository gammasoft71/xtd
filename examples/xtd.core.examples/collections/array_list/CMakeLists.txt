cmake_minimum_required(VERSION 3.20)

project(array_list)
find_package(xtd REQUIRED)
add_sources(README.md src/array_list.cpp)
target_type(CONSOLE_APPLICATION)
