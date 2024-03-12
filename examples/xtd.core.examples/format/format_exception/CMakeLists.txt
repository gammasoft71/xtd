cmake_minimum_required(VERSION 3.20)

project(format_exception)
find_package(xtd REQUIRED)
add_sources(src/format_exception.cpp)
target_type(CONSOLE_APPLICATION)
