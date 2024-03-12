cmake_minimum_required(VERSION 3.20)

project(assert_is_empty)
find_package(xtd REQUIRED)
add_sources(src/assert_is_empty.cpp)
target_type(TEST_APPLICATION)
