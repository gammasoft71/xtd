cmake_minimum_required(VERSION 3.5)

project(assert_are_same)
find_package(xtd REQUIRED)
add_sources(README.md src/assert_are_same.cpp)
target_type(TEST_APPLICATION)
