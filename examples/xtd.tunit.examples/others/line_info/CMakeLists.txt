cmake_minimum_required(VERSION 3.20)

project(line_info)
find_package(xtd REQUIRED)
add_sources(README.md src/line_info.cpp)
target_type(TEST_APPLICATION)
