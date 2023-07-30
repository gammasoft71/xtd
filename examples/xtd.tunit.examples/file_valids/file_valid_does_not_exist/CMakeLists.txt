cmake_minimum_required(VERSION 3.5)

project(file_valid_does_not_exist)
find_package(xtd REQUIRED)
add_sources(README.md src/file_valid_does_not_exist.cpp)
target_type(TEST_APPLICATION)
