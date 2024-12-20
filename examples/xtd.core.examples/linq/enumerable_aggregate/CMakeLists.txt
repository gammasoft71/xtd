cmake_minimum_required(VERSION 3.20)

project(enumerable_aggregate)
find_package(xtd REQUIRED)
add_sources(README.md src/enumerable_aggregate.cpp)
target_type(CONSOLE_APPLICATION)
