cmake_minimum_required(VERSION 3.3)

project(formatf_class_with_specified_formating)
find_package(xtd REQUIRED)
add_sources(src/formatf_class_with_specified_formating.cpp)
target_type(CONSOLE_APPLICATION)
