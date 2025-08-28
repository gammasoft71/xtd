cmake_minimum_required(VERSION 3.20)

project(enumerable_distinct)
find_package(xtd REQUIRED)
add_sources(README.md src/enumerable_distinct.cpp)
target_type(CONSOLE_APPLICATION)
