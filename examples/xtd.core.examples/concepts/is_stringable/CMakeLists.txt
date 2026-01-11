cmake_minimum_required(VERSION 3.20)

project(is_stringable)
find_package(xtd REQUIRED)
add_sources(README.md src/is_stringable.cpp)
target_type(CONSOLE_APPLICATION)
