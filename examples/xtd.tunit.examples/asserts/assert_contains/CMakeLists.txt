cmake_minimum_required(VERSION 3.5)

project(assert_contains)
find_package(xtd REQUIRED)
add_sources(README.md src/assert_contains.cpp)
target_type(TEST_APPLICATION)
