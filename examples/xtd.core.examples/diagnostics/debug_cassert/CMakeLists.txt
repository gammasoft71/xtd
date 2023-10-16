cmake_minimum_required(VERSION 3.20)

project(debug_cassert)
find_package(xtd REQUIRED)
add_sources(README.md src/debug_cassert.cpp)
target_type(CONSOLE_APPLICATION)
