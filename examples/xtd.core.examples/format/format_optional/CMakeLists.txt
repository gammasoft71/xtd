cmake_minimum_required(VERSION 3.3)

project(format_optional)
find_package(xtd REQUIRED)
add_sources(src/format_optional.cpp)
target_type(CONSOLE_APPLICATION)
