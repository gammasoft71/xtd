cmake_minimum_required(VERSION 3.3)

project(format_class_with_specified_formating)
find_package(xtd REQUIRED)
add_sources(src/format_class_with_specified_formating.cpp)
target_type(CONSOLE_APPLICATION)
