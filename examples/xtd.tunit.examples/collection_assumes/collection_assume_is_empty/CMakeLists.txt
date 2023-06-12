cmake_minimum_required(VERSION 3.3)

project(collection_assume_is_empty)
find_package(xtd REQUIRED)
add_sources(README.md src/collection_assume_is_empty.cpp)
target_type(TEST_APPLICATION)
