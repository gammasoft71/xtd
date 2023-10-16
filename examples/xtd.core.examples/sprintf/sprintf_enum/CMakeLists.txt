cmake_minimum_required(VERSION 3.20)

project(format_enum)
find_package(xtd REQUIRED)
add_sources(src/format_enum.cpp)
target_type(CONSOLE_APPLICATION)
