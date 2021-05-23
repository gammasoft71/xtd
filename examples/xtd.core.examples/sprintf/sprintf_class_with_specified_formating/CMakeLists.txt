cmake_minimum_required(VERSION 3.3)

project(sprintf_class_with_specified_formating)
find_package(xtd REQUIRED)
add_sources(src/sprintf_class_with_specified_formating.cpp)
target_type(CONSOLE_APPLICATION)
