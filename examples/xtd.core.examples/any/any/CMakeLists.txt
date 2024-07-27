cmake_minimum_required(VERSION 3.20)

project(any)
find_package(xtd REQUIRED)
add_sources(README.md src/any.cpp)
target_type(CONSOLE_APPLICATION)
