cmake_minimum_required(VERSION 3.3)

project(assert_is_less)
find_package(xtd REQUIRED)
add_sources(src/assert_is_less.cpp)
target_type(TEST_APPLICATION)
