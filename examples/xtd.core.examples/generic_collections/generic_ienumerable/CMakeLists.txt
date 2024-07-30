cmake_minimum_required(VERSION 3.20)

project(generic_ienumerable)
find_package(xtd REQUIRED)
add_sources(README.md src/generic_ienumerable.cpp)
target_type(CONSOLE_APPLICATION)
