cmake_minimum_required(VERSION 3.5)

project(concat)
find_package(xtd REQUIRED)
add_sources(README.md src/concat.cpp)
target_type(CONSOLE_APPLICATION)
