cmake_minimum_required(VERSION 3.20)

project(format_associative_containers)
find_package(xtd REQUIRED)
add_sources(README.md src/format_associative_containers.cpp)
target_type(CONSOLE_APPLICATION)
