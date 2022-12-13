cmake_minimum_required(VERSION 3.3)

project(bit_converter_is_big_endian)
find_package(xtd REQUIRED)
add_sources(README.md src/bit_converter_is_big_endian.cpp)
target_type(CONSOLE_APPLICATION)
