cmake_minimum_required(VERSION 3.20)

project(linq_from)
find_package(xtd REQUIRED)
add_sources(README.md src/linq_from.cpp)
target_type(CONSOLE_APPLICATION)
