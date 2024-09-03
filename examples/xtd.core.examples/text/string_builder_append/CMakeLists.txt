cmake_minimum_required(VERSION 3.20)

project(string_builder_append)
find_package(xtd REQUIRED)
add_sources(README.md src/string_builder_append.cpp)
target_type(CONSOLE_APPLICATION)
