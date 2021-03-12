cmake_minimum_required(VERSION 3.3)

project(format_pair)
find_package(xtd REQUIRED)
add_sources(src/format_pair.cpp)
target_type(CONSOLE_APPLICATION)
