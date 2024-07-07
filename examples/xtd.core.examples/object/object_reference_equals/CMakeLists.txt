cmake_minimum_required(VERSION 3.20)

project(object_reference_equals)
find_package(xtd REQUIRED)
add_sources(README.md src/object_reference_equals.cpp)
target_type(CONSOLE_APPLICATION)
