cmake_minimum_required(VERSION 3.20)

project(ienumerator)
find_package(xtd REQUIRED)
add_sources(README.md src/ienumerator.cpp)
target_type(CONSOLE_APPLICATION)
