cmake_minimum_required(VERSION 3.20)

project(variant)
find_package(xtd REQUIRED)
add_sources(README.md src/variant.cpp)
target_type(CONSOLE_APPLICATION)
