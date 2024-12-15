cmake_minimum_required(VERSION 3.20)

project(format_time_span)
find_package(xtd REQUIRED)
add_sources(README.md src/format_time_span.cpp)
target_type(CONSOLE_APPLICATION)
