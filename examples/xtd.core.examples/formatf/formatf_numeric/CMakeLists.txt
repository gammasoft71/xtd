cmake_minimum_required(VERSION 3.3)

project(formatf_numeric)
find_package(xtd REQUIRED)
add_sources(src/formatf_numeric.cpp)
target_type(CONSOLE_APPLICATION)
