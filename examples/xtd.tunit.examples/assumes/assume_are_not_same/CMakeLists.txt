cmake_minimum_required(VERSION 3.20)

project(assume_are_not_same)
find_package(xtd REQUIRED)
add_sources(README.md src/assume_are_not_same.cpp)
target_type(TEST_APPLICATION)
