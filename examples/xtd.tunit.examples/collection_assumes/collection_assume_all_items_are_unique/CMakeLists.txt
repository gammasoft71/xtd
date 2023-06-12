cmake_minimum_required(VERSION 3.3)

project(collection_assume_all_items_are_unique)
find_package(xtd REQUIRED)
add_sources(README.md src/collection_assume_all_items_are_unique.cpp)
target_type(TEST_APPLICATION)
