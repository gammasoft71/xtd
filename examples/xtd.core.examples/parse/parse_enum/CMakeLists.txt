cmake_minimum_required(VERSION 3.20)

project(parse_enum)
find_package(xtd REQUIRED)
add_sources(README.md src/parse_enum.cpp)
target_type(CONSOLE_APPLICATION)
