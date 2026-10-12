cmake_minimum_required(VERSION 3.20)

project(parallel_for_each)
find_package(xtd REQUIRED)
add_sources(README.md src/parallel_for_each.cpp)
target_type(CONSOLE_APPLICATION)
