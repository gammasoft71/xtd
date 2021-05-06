cmake_minimum_required(VERSION 3.3)

project(assert_is_zero)
find_package(xtd REQUIRED)
add_sources(src/assert_is_zero.cpp)
target_type(TEST_APPLICATION)
