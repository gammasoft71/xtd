cmake_minimum_required(VERSION 3.3)

project(assert_is_not_empty)
find_package(xtd REQUIRED)
add_sources(src/assert_is_not_empty.cpp)
target_type(TEST_APPLICATION)
