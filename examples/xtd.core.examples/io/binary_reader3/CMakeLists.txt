cmake_minimum_required(VERSION 3.3)

project(binary_reader3)
find_package(xtd REQUIRED)
add_sources(README.md src/binary_reader3.cpp)
target_type(CONSOLE_APPLICATION)
