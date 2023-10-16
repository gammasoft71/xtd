cmake_minimum_required(VERSION 3.20)

project(string_format)
find_package(xtd REQUIRED)
add_sources(README.md src/string_format.cpp)
target_type(CONSOLE_APPLICATION)
