cmake_minimum_required(VERSION 3.20)

project(icomparable)
find_package(xtd REQUIRED)
add_sources(README.md src/icomparable.cpp)
target_type(CONSOLE_APPLICATION)
