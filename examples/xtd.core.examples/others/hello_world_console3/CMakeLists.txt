cmake_minimum_required(VERSION 3.3)

project(hello_world_console3)
find_package(xtd REQUIRED)
add_sources(src/hello_world_console3.cpp)
target_type(CONSOLE_APPLICATION)
