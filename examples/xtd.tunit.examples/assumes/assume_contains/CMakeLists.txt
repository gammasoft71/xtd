cmake_minimum_required(VERSION 3.20)

project(assume_contains)
find_package(xtd REQUIRED)
add_sources(README.md src/assume_contains.cpp)
target_type(TEST_APPLICATION)
