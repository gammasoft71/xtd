cmake_minimum_required(VERSION 3.20)

project(collection_assert_contains)
find_package(xtd REQUIRED)
add_sources(README.md src/collection_assert_contains.cpp)
target_type(TEST_APPLICATION)
