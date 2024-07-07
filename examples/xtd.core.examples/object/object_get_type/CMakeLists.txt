cmake_minimum_required(VERSION 3.20)

project(object_get_type)
find_package(xtd REQUIRED)
add_sources(README.md src/object_get_type.cpp)
target_type(CONSOLE_APPLICATION)
