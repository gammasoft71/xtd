cmake_minimum_required(VERSION 3.20)

project(to_string)
find_package(xtd REQUIRED)
add_sources(README.md src/to_string.cpp)
target_type(CONSOLE_APPLICATION)
