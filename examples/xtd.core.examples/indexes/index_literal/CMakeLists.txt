cmake_minimum_required(VERSION 3.20)

project(index_literal)
find_package(xtd REQUIRED)
add_sources(README.md src/index_literal.cpp)
target_type(CONSOLE_APPLICATION)
