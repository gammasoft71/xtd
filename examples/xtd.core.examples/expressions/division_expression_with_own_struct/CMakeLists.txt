cmake_minimum_required(VERSION 3.20)

project(division_expression_with_own_struct)
find_package(xtd REQUIRED)
add_sources(README.md src/division_expression_with_own_struct.cpp)
target_type(CONSOLE_APPLICATION)
