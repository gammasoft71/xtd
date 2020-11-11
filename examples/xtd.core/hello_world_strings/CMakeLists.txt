cmake_minimum_required(VERSION 3.3)

project(hello_world_strings)
find_package(xtd REQUIRED)
add_sources(src/hello_world_strings.cpp)
target_type(CONSOLE_APPLICATION)
