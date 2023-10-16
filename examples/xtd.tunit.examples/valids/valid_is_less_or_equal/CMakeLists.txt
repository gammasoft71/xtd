cmake_minimum_required(VERSION 3.20)

project(valid_is_less_or_equal)
find_package(xtd REQUIRED)
add_sources(README.md src/valid_is_less_or_equal.cpp)
target_type(TEST_APPLICATION)
