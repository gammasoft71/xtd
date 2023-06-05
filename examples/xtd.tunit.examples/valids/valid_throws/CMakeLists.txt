cmake_minimum_required(VERSION 3.3)

project(valid_throws)
find_package(xtd REQUIRED)
add_sources(README.md src/valid_throws.cpp)
target_type(TEST_APPLICATION)
