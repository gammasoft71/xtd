cmake_minimum_required(VERSION 3.3)

project(sprintf)
find_package(xtd REQUIRED)
add_sources(src/sprintf.cpp)
target_type(CONSOLE_APPLICATION)
