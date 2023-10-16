cmake_minimum_required(VERSION 3.20)

project(collection_assume_are_not_equivalent)
find_package(xtd REQUIRED)
add_sources(README.md src/collection_assume_are_not_equivalent.cpp)
target_type(TEST_APPLICATION)
