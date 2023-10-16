cmake_minimum_required(VERSION 3.20)

project(string_valid_does_not_start_with)
find_package(xtd REQUIRED)
add_sources(README.md src/string_valid_does_not_start_with.cpp)
target_type(TEST_APPLICATION)
