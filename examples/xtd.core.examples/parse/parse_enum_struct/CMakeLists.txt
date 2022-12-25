cmake_minimum_required(VERSION 3.3)

project(parse_enum_struct)
find_package(xtd REQUIRED)
add_sources(README.md src/parse_enum_struct.cpp)
target_type(CONSOLE_APPLICATION)
