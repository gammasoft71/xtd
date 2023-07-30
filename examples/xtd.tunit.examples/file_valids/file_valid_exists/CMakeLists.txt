cmake_minimum_required(VERSION 3.5)

project(file_valid_exists)
find_package(xtd REQUIRED)
add_sources(README.md src/file_valid_exists.cpp)
target_type(TEST_APPLICATION)
