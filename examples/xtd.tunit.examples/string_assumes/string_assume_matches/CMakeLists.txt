cmake_minimum_required(VERSION 3.3)

project(string_assume_matches)
find_package(xtd REQUIRED)
add_sources(README.md src/string_assume_matches.cpp)
target_type(TEST_APPLICATION)
