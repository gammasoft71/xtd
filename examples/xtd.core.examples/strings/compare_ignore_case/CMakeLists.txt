cmake_minimum_required(VERSION 3.20)

project(compare_ignore_case)
find_package(xtd REQUIRED)
add_sources(README.md src/compare_ignore_case.cpp)
target_type(CONSOLE_APPLICATION)
