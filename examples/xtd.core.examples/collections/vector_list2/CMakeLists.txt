cmake_minimum_required(VERSION 3.20)

project(vector_list2)
find_package(xtd REQUIRED)
add_sources(src/vector_list2.cpp)
target_type(CONSOLE_APPLICATION)
