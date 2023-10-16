cmake_minimum_required(VERSION 3.20)

project(hello_world_console)
find_package(xtd REQUIRED)
add_sources(README.md src/hello_world_console.cpp)
target_type(CONSOLE_APPLICATION)
