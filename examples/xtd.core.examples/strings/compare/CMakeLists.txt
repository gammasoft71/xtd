cmake_minimum_required(VERSION 3.3)

project(compare)
find_package(xtd REQUIRED)
add_sources(src/compare.cpp)
target_type(CONSOLE_APPLICATION)
