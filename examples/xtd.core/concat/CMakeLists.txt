cmake_minimum_required(VERSION 3.3)

project(concat)
find_package(xtd REQUIRED)
add_sources(src/concat.cpp)
target_type(CONSOLE_APPLICATION)
