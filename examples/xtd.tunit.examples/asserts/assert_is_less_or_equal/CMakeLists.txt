cmake_minimum_required(VERSION 3.5)

project(assert_is_less_or_equal)
find_package(xtd REQUIRED)
add_sources(README.md src/assert_is_less_or_equal.cpp)
target_type(TEST_APPLICATION)
