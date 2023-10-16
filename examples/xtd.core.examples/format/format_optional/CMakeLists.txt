cmake_minimum_required(VERSION 3.20)

project(format_optional)
find_package(xtd REQUIRED)
add_sources(README.md src/format_optional.cpp)
target_type(CONSOLE_APPLICATION)
