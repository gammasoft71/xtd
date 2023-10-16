cmake_minimum_required(VERSION 3.20)

project(assume_throws)
find_package(xtd REQUIRED)
add_sources(README.md src/assume_throws.cpp)
target_type(TEST_APPLICATION)
