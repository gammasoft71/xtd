cmake_minimum_required(VERSION 3.3)

project(vector_list)
find_package(xtd REQUIRED)
add_sources(src/vector_list.cpp)
target_type(CONSOLE_APPLICATION)
