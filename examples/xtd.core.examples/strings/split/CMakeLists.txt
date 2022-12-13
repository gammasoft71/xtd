cmake_minimum_required(VERSION 3.3)

project(split)
find_package(xtd REQUIRED)
add_sources(README.md src/split.cpp)
target_type(CONSOLE_APPLICATION)
