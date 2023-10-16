cmake_minimum_required(VERSION 3.20)

project(enum_struct_ut)
find_package(xtd REQUIRED)
add_sources(README.md src/enum_struct_ut.cpp)
target_type(CONSOLE_APPLICATION)
