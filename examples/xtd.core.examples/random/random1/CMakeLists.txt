cmake_minimum_required(VERSION 3.3)

project(random1)
find_package(xtd REQUIRED)
add_sources(src/random1.cpp)
target_type(CONSOLE_APPLICATION)
