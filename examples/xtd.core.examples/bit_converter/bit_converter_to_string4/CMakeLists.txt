cmake_minimum_required(VERSION 3.20)

project(bit_converter_to_string4)
find_package(xtd REQUIRED)
add_sources(README.md src/bit_converter_to_string4.cpp)
target_type(CONSOLE_APPLICATION)
