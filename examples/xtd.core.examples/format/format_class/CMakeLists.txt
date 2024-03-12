cmake_minimum_required(VERSION 3.20)

project(format_class)
find_package(xtd REQUIRED)
add_sources(src/format_class.cpp)
target_type(CONSOLE_APPLICATION)
