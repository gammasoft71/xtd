cmake_minimum_required(VERSION 3.20)

project(expression)
find_package(xtd REQUIRED)
add_sources(README.md src/expression.cpp)
target_type(CONSOLE_APPLICATION)
