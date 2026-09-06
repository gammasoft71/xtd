cmake_minimum_required(VERSION 3.20)

project(divide_expression_with_own_struct)
find_package(xtd REQUIRED)
add_sources(README.md src/divide_expression_with_own_struct.cpp)
target_type(CONSOLE_APPLICATION)
