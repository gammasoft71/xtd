cmake_minimum_required(VERSION 3.20)

project(arg_expression)
find_package(xtd REQUIRED)
add_sources(README.md src/arg_expression.cpp)
target_type(CONSOLE_APPLICATION)
