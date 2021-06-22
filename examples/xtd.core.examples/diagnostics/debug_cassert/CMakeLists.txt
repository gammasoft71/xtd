cmake_minimum_required(VERSION 3.3)

project(debug_cassert)
find_package(xtd REQUIRED)
add_sources(src/debug_cassert.cpp)
target_type(CONSOLE_APPLICATION)
