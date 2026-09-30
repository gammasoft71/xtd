cmake_minimum_required(VERSION 3.20)

project(generic_ilist)
find_package(xtd REQUIRED)
add_sources(README.md src/generic_ilist.cpp)
target_type(CONSOLE_APPLICATION)
