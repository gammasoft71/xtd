cmake_minimum_required(VERSION 3.5)

project(bit_converter_endianness)
find_package(xtd REQUIRED)
add_sources(README.md src/bit_converter_endianness.cpp)
target_type(CONSOLE_APPLICATION)
