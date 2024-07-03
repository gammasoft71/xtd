cmake_minimum_required(VERSION 3.20)

project(iformatable)
find_package(xtd REQUIRED)
add_sources(README.md src/iformatable.cpp)
target_type(CONSOLE_APPLICATION)
