cmake_minimum_required(VERSION 3.20)

project(format_sequence_containers)
find_package(xtd REQUIRED)
add_sources(README.md src/format_sequence_containers.cpp)
target_type(CONSOLE_APPLICATION)
