cmake_minimum_required(VERSION 3.3)

project(static)
find_package(xtd REQUIRED)
add_sources(src/static.cpp)
target_type(CONSOLE_APPLICATION)
