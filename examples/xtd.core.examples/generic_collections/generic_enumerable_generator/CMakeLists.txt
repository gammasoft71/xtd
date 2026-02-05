cmake_minimum_required(VERSION 3.20)

project(generic_enumerable_generator)
find_package(xtd REQUIRED)
add_sources(README.md src/generic_enumerable_generator.cpp)
target_type(CONSOLE_APPLICATION)
