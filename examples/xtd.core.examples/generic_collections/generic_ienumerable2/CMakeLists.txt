cmake_minimum_required(VERSION 3.20)

project(generic_ienumerable2)
find_package(xtd REQUIRED)
add_sources(README.md src/generic_ienumerable2.cpp)
target_type(CONSOLE_APPLICATION)
