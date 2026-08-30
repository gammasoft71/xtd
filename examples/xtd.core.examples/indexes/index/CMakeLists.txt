cmake_minimum_required(VERSION 3.20)

project(index)
find_package(xtd REQUIRED)
add_sources(README.md src/index.cpp)
target_type(CONSOLE_APPLICATION)
