cmake_minimum_required(VERSION 3.20)

project(bit_converter_is_little_endian)
find_package(xtd REQUIRED)
add_sources(README.md src/bit_converter_is_little_endian.cpp)
target_type(CONSOLE_APPLICATION)
