cmake_minimum_required(VERSION 3.20)

project(compare)
find_package(xtd REQUIRED)
add_sources(README.md src/compare.cpp)
target_type(CONSOLE_APPLICATION)
