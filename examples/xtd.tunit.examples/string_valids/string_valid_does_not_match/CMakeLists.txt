cmake_minimum_required(VERSION 3.3)

project(string_valid_does_not_match)
find_package(xtd REQUIRED)
add_sources(README.md src/string_valid_does_not_match.cpp)
target_type(TEST_APPLICATION)
