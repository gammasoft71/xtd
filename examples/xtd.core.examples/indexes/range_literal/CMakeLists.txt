cmake_minimum_required(VERSION 3.20)

project(range_literal)
find_package(xtd REQUIRED)
add_sources(README.md src/range_literal.cpp)
target_type(CONSOLE_APPLICATION)
