cmake_minimum_required(VERSION 3.20)

project(generic_stack)
find_package(xtd REQUIRED)
add_sources(README.md src/generic_stack.cpp)
target_type(CONSOLE_APPLICATION)
