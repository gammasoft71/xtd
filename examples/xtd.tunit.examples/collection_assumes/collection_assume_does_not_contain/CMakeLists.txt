cmake_minimum_required(VERSION 3.20)

project(collection_assume_does_not_contain)
find_package(xtd REQUIRED)
add_sources(README.md src/collection_assume_does_not_contain.cpp)
target_type(TEST_APPLICATION)
