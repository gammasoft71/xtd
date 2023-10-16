cmake_minimum_required(VERSION 3.20)

project(file_assume_are_equal)
find_package(xtd REQUIRED)
add_sources(README.md src/file_assume_are_equal.cpp)
target_type(TEST_APPLICATION)
