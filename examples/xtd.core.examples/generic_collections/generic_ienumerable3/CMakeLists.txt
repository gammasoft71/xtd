cmake_minimum_required(VERSION 3.20)

project(generic_ienumerable3)
find_package(xtd REQUIRED)
add_sources(README.md src/generic_ienumerable3.cpp)
target_type(CONSOLE_APPLICATION)
