cmake_minimum_required(VERSION 3.20)

project(assume_is_positive)
find_package(xtd REQUIRED)
add_sources(README.md src/assume_is_positive.cpp)
target_type(TEST_APPLICATION)
