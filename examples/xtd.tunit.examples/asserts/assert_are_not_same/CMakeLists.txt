cmake_minimum_required(VERSION 3.20)

project(assert_are_not_same)
find_package(xtd REQUIRED)
add_sources(src/assert_are_not_same.cpp)
target_type(TEST_APPLICATION)
