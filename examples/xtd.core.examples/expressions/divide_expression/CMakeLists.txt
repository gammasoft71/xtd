cmake_minimum_required(VERSION 3.20)

project(divide_expression)
find_package(xtd REQUIRED)
add_sources(README.md src/divide_expression.cpp)
target_type(CONSOLE_APPLICATION)
