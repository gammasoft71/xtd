cmake_minimum_required(VERSION 3.3)

project(to_byte)
find_package(xtd REQUIRED)
add_sources(src/to_byte.cpp)
target_type(CONSOLE_APPLICATION)
