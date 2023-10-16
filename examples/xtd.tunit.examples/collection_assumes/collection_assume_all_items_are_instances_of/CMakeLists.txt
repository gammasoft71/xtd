cmake_minimum_required(VERSION 3.20)

project(collection_assume_all_items_are_instances_of)
find_package(xtd REQUIRED)
add_sources(README.md src/collection_assume_all_items_are_instances_of.cpp)
target_type(TEST_APPLICATION)
