cmake_minimum_required(VERSION 3.20)

project(generic_list_convert_all)
find_package(xtd REQUIRED)
add_sources(README.md src/generic_list_convert_all.cpp)
target_type(CONSOLE_APPLICATION)
