cmake_minimum_required(VERSION 3.20)

project(brushes)
find_package(xtd REQUIRED)
add_sources(README.md src/brushes.cpp)
target_type(CONSOLE_APPLICATION)
