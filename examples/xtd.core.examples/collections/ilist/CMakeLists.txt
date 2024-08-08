cmake_minimum_required(VERSION 3.20)

project(ilist)
find_package(xtd REQUIRED)
add_sources(README.md src/ilist.cpp)
target_type(CONSOLE_APPLICATION)
