cmake_minimum_required(VERSION 3.3)

project(format_unordered_associative_containers)
find_package(xtd REQUIRED)
add_sources(src/format_unordered_associative_containers.cpp)
target_type(CONSOLE_APPLICATION)
