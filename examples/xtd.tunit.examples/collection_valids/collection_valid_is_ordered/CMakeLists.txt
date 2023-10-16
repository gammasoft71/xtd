cmake_minimum_required(VERSION 3.20)

project(collection_valid_is_ordered)
find_package(xtd REQUIRED)
add_sources(README.md src/collection_valid_is_ordered.cpp)
target_type(TEST_APPLICATION)
