cmake_minimum_required(VERSION 3.20)

project(debug)
find_package(xtd REQUIRED)
add_sources(README.md src/debug.cpp)
target_type(CONSOLE_APPLICATION)
