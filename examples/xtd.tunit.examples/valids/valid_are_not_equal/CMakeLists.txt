cmake_minimum_required(VERSION 3.20)

project(valid_are_not_equal)
find_package(xtd REQUIRED)
add_sources(README.md src/valid_are_not_equal.cpp)
target_type(TEST_APPLICATION)
