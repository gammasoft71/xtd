cmake_minimum_required(VERSION 3.3)

project(parse_boolean)
find_package(xtd REQUIRED)
add_sources(README.md src/parse_boolean.cpp)
target_type(CONSOLE_APPLICATION)
