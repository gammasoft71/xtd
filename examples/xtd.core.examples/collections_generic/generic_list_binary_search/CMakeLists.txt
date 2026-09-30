cmake_minimum_required(VERSION 3.20)

project(generic_list_binary_search)
find_package(xtd REQUIRED)
add_sources(README.md src/generic_list_binary_search.cpp)
target_type(CONSOLE_APPLICATION)
