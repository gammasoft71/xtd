cmake_minimum_required(VERSION 3.3)

project(assert_fail)
find_package(xtd REQUIRED)
add_sources(src/assert_fail.cpp)
target_type(TEST_APPLICATION)
