cmake_minimum_required(VERSION 3.20)

project(convert_string)
find_package(xtd REQUIRED)
add_sources(README.md src/convert_string.cpp)
target_type(CONSOLE_APPLICATION)
