cmake_minimum_required(VERSION 3.20)

project(vector_list)
find_package(xtd REQUIRED)
add_sources(src/vector_list.cpp)
target_type(CONSOLE_APPLICATION)
