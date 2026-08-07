cmake_minimum_required(VERSION 3.20)

project(enumerable_take_while)
find_package(xtd REQUIRED)
add_sources(README.md src/enumerable_take_while.cpp)
target_type(CONSOLE_APPLICATION)
