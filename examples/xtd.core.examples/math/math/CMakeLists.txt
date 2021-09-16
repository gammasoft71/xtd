cmake_minimum_required(VERSION 3.3)

project(math)
find_package(xtd REQUIRED)
add_sources(src/math.cpp)
target_type(CONSOLE_APPLICATION)
