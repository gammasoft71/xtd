cmake_minimum_required(VERSION 3.20)

project(hello_world_ustring)
find_package(xtd REQUIRED)
add_sources(README.md src/hello_world_ustring.cpp)
target_type(CONSOLE_APPLICATION)
