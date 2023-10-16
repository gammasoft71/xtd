cmake_minimum_required(VERSION 3.20)

project(collection_assert_are_equal)
find_package(xtd REQUIRED)
add_sources(README.md src/collection_assert_are_equal.cpp)
target_type(TEST_APPLICATION)
