cmake_minimum_required(VERSION 3.20)

project(to_int32)
find_package(xtd REQUIRED)
add_sources(README.md src/to_int32.cpp)
target_type(CONSOLE_APPLICATION)
