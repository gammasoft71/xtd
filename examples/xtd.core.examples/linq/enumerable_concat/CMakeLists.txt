cmake_minimum_required(VERSION 3.20)

project(enumerable_concat)
find_package(xtd REQUIRED)
add_sources(README.md src/enumerable_concat.cpp)
target_type(CONSOLE_APPLICATION)
