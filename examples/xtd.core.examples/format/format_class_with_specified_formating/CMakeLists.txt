cmake_minimum_required(VERSION 3.20)

project(format_class_with_specified_formating)
find_package(xtd REQUIRED)
add_sources(README.md src/format_class_with_specified_formating.cpp)
target_type(CONSOLE_APPLICATION)
