cmake_minimum_required(VERSION 3.3)

project(xtd_format)
find_package(xtd REQUIRED)
add_sources(src/xtd_format.cpp)
target_type(CONSOLE_APPLICATION)
