cmake_minimum_required(VERSION 3.20)

project(string_assume_does_not_contain)
find_package(xtd REQUIRED)
add_sources(README.md src/string_assume_does_not_contain.cpp)
target_type(TEST_APPLICATION)
