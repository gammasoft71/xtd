cmake_minimum_required(VERSION 3.3)

project(format_any)
find_package(xtd REQUIRED)
add_sources(src/format_any.cpp)
target_type(CONSOLE_APPLICATION)
