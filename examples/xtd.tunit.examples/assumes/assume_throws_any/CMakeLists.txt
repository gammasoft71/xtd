cmake_minimum_required(VERSION 3.5)

project(assume_throws_any)
find_package(xtd REQUIRED)
add_sources(README.md src/assume_throws_any.cpp)
target_type(TEST_APPLICATION)
