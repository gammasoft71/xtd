cmake_minimum_required(VERSION 3.20)

project(string_assume_are_not_equal_ignoring_case)
find_package(xtd REQUIRED)
add_sources(README.md src/string_assume_are_not_equal_ignoring_case.cpp)
target_type(TEST_APPLICATION)
