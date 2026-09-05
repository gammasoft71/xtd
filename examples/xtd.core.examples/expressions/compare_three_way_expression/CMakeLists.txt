cmake_minimum_required(VERSION 3.20)

project(compare_three_way_expression)
find_package(xtd REQUIRED)
add_sources(README.md src/compare_three_way_expression.cpp)
target_type(CONSOLE_APPLICATION)
