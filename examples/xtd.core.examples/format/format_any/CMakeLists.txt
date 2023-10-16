cmake_minimum_required(VERSION 3.20)

project(format_any)
find_package(xtd REQUIRED)
add_sources(README.md src/format_any.cpp)
target_type(CONSOLE_APPLICATION)
