cmake_minimum_required(VERSION 3.5)

project(vector_list)
find_package(xtd REQUIRED)
add_sources(README.md src/vector_list.cpp)
target_type(CONSOLE_APPLICATION)
