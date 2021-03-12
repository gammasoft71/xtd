cmake_minimum_required(VERSION 3.3)

project(format_tuple)
find_package(xtd REQUIRED)
add_sources(src/format_tuple.cpp)
target_type(CONSOLE_APPLICATION)
