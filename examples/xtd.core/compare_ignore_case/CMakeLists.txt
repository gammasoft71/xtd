cmake_minimum_required(VERSION 3.3)

project(compare_ignore_case)
find_package(xtd REQUIRED)
add_sources(src/compare_ignore_case.cpp)
target_type(CONSOLE_APPLICATION)
