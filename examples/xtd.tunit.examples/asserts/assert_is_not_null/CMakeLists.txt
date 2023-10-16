cmake_minimum_required(VERSION 3.20)

project(assert_is_not_null)
find_package(xtd REQUIRED)
add_sources(README.md src/assert_is_not_null.cpp)
target_type(TEST_APPLICATION)
