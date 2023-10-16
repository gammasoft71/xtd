cmake_minimum_required(VERSION 3.20)

project(enum_class_parse)
find_package(xtd REQUIRED)
add_sources(README.md src/enum_class_parse.cpp)
target_type(CONSOLE_APPLICATION)
