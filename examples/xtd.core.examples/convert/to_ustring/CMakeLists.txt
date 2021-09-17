cmake_minimum_required(VERSION 3.3)

project(to_ustring)
find_package(xtd REQUIRED)
add_sources(src/to_ustring.cpp)
target_type(CONSOLE_APPLICATION)
