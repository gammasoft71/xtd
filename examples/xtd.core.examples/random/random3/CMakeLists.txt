cmake_minimum_required(VERSION 3.3)

project(random3)
find_package(xtd REQUIRED)
add_sources(src/random3.cpp)
target_type(CONSOLE_APPLICATION)
