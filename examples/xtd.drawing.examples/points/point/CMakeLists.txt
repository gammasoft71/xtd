cmake_minimum_required(VERSION 3.20)

project(point)
find_package(xtd REQUIRED)
add_sources(README.md src/point.cpp)
target_type(CONSOLE_APPLICATION)
