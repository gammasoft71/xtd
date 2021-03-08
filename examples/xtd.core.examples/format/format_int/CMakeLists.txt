cmake_minimum_required(VERSION 3.3)

project(format_int)
find_package(xtd REQUIRED)
add_sources(src/format_int.cpp)
target_type(CONSOLE_APPLICATION)
