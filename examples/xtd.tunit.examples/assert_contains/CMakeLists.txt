cmake_minimum_required(VERSION 3.3)

project(assert_contains)
find_package(xtd REQUIRED)
add_sources(src/assert_contains.cpp)
target_type(TEST_APPLICATION)
