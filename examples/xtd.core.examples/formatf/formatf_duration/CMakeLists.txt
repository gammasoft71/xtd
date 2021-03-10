cmake_minimum_required(VERSION 3.3)

project(format_duration)
find_package(xtd REQUIRED)
add_sources(src/format_duration.cpp)
target_type(CONSOLE_APPLICATION)
