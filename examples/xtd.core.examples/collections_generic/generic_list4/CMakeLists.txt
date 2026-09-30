cmake_minimum_required(VERSION 3.20)

project(generic_list4)
find_package(xtd REQUIRED)
add_sources(README.md src/generic_list4.cpp)
target_type(CONSOLE_APPLICATION)
