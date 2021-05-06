cmake_minimum_required(VERSION 3.3)

project(assert_throws)
find_package(xtd REQUIRED)
add_sources(src/assert_throws.cpp)
target_type(TEST_APPLICATION)
