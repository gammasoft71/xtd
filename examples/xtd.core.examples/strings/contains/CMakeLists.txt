cmake_minimum_required(VERSION 3.5)

project(contains)
find_package(xtd REQUIRED)
add_sources(README.md src/contains.cpp)
target_type(CONSOLE_APPLICATION)
