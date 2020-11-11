cmake_minimum_required(VERSION 3.3)

project(assert_are_equal)
find_package(xtd REQUIRED)
add_sources(src/assert_are_equal.cpp)
target_type(TEST_APPLICATION)
