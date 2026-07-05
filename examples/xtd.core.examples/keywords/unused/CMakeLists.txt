cmake_minimum_required(VERSION 3.20)

project(unused)
find_package(xtd REQUIRED)
add_sources(README.md src/unused.cpp)
target_type(CONSOLE_APPLICATION)
