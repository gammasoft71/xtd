cmake_minimum_required(VERSION 3.3)

project(line_info)
find_package(xtd REQUIRED)
add_sources(src/line_info.cpp)
target_type(TEST_APPLICATION)
