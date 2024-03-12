cmake_minimum_required(VERSION 3.20)

project(format_numeric)
find_package(xtd REQUIRED)
add_sources(src/format_numeric.cpp)
target_type(CONSOLE_APPLICATION)
