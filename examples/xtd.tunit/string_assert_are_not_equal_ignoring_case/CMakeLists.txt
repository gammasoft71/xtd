cmake_minimum_required(VERSION 3.3)

project(string_assert_are_not_equal_ignoring_case)
find_package(xtd REQUIRED)
add_sources(src/string_assert_are_equal_ignoring_case.cpp)
target_type(TEST_APPLICATION)
