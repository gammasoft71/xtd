cmake_minimum_required(VERSION 3.5)

project(collection_assume)
find_package(xtd REQUIRED)
add_sources(README.md src/collection_assume.cpp)
target_type(TEST_APPLICATION)
