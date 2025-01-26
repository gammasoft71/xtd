cmake_minimum_required(VERSION 3.20)

project(span_from_memory)
find_package(xtd REQUIRED)
add_sources(README.md src/span_from_memory.cpp)
target_type(CONSOLE_APPLICATION)
