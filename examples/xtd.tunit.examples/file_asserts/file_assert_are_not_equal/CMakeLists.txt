cmake_minimum_required(VERSION 3.20)

project(file_assert_are_not_equal)
find_package(xtd REQUIRED)
add_sources(README.md src/file_assert_are_not_equal.cpp)
target_type(TEST_APPLICATION)
