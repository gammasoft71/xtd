cmake_minimum_required(VERSION 3.20)

project(parse_enum_struct)
find_package(xtd REQUIRED)
add_sources(README.md src/parse_enum_struct.cpp)
target_type(CONSOLE_APPLICATION)
