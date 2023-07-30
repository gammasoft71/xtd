cmake_minimum_required(VERSION 3.5)

project(assert_throws)
find_package(xtd REQUIRED)
add_sources(README.md src/assert_throws.cpp)
target_type(TEST_APPLICATION)
