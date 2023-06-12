cmake_minimum_required(VERSION 3.3)

project(collection_assume_contains)
find_package(xtd REQUIRED)
add_sources(README.md src/collection_assume_contains.cpp)
target_type(TEST_APPLICATION)
