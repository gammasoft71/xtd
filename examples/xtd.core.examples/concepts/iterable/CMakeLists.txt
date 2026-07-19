cmake_minimum_required(VERSION 3.20)

project(iterable)
find_package(xtd REQUIRED)
add_sources(README.md src/iterable.cpp)
target_type(CONSOLE_APPLICATION)
