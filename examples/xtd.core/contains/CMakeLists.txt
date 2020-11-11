cmake_minimum_required(VERSION 3.3)

project(contains)
find_package(xtd REQUIRED)
add_sources(src/contains.cpp)
target_type(CONSOLE_APPLICATION)
