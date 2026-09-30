cmake_minimum_required(VERSION 3.20)

project(generic_list_for_each)
find_package(xtd REQUIRED)
add_sources(README.md src/generic_list_for_each.cpp)
target_type(CONSOLE_APPLICATION)
