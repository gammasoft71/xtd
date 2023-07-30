cmake_minimum_required(VERSION 3.5)

project(assume_is_null)
find_package(xtd REQUIRED)
add_sources(README.md src/assume_is_null.cpp)
target_type(TEST_APPLICATION)
