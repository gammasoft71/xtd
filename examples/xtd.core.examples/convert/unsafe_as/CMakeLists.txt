cmake_minimum_required(VERSION 3.20)

project(unsafe_as)
find_package(xtd REQUIRED)
add_sources(README.md src/unsafe_as.cpp)
target_type(CONSOLE_APPLICATION)
