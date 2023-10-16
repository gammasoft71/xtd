cmake_minimum_required(VERSION 3.20)

project(format_class_object)
find_package(xtd REQUIRED)
add_sources(README.md src/format_class_object.cpp)
target_type(CONSOLE_APPLICATION)
