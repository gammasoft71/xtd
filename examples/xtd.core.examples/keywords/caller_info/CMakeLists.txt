cmake_minimum_required(VERSION 3.3)

project(caller_info)
find_package(xtd REQUIRED)
add_sources(src/caller_info.cpp)
target_type(TEST_APPLICATION)
