cmake_minimum_required(VERSION 3.3)

project(join)
find_package(xtd REQUIRED)
add_sources(src/join.cpp)
target_type(CONSOLE_APPLICATION)
