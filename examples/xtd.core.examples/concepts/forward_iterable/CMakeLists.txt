cmake_minimum_required(VERSION 3.20)

project(forward_iterable)
find_package(xtd REQUIRED)
add_sources(README.md src/forward_iterable.cpp)
target_type(CONSOLE_APPLICATION)
