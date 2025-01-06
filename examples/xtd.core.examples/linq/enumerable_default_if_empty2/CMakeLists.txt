cmake_minimum_required(VERSION 3.20)

project(enumerable_default_if_empty2)
find_package(xtd REQUIRED)
add_sources(README.md src/enumerable_default_if_empty2.cpp)
target_type(CONSOLE_APPLICATION)
