cmake_minimum_required(VERSION 3.20)

project(ienumerable)
find_package(xtd REQUIRED)
add_sources(README.md src/ienumerable.cpp)
target_type(CONSOLE_APPLICATION)
