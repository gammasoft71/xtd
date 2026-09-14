cmake_minimum_required(VERSION 3.20)

project(bit_converter_to_string3)
find_package(xtd REQUIRED)
add_sources(README.md src/bit_converter_to_string3.cpp)
target_type(CONSOLE_APPLICATION)
