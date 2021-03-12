cmake_minimum_required(VERSION 3.3)

project(format_pointer)
find_package(xtd REQUIRED)
add_sources(src/format_pointer.cpp)
target_type(CONSOLE_APPLICATION)
