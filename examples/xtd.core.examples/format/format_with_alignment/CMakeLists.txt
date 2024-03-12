cmake_minimum_required(VERSION 3.20)

project(format_with_alignment)
find_package(xtd REQUIRED)
add_sources(src/format_with_alignment.cpp)
target_type(CONSOLE_APPLICATION)
