cmake_minimum_required(VERSION 3.20)

project(assume_is_zero)
find_package(xtd REQUIRED)
add_sources(README.md src/assume_is_zero.cpp)
target_type(TEST_APPLICATION)
