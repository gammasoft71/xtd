cmake_minimum_required(VERSION 3.20)

project(assert_is_positive)
find_package(xtd REQUIRED)
add_sources(src/assert_is_positive.cpp)
target_type(TEST_APPLICATION)
