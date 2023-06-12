cmake_minimum_required(VERSION 3.3)

project(directory_valid_does_not_exist)
find_package(xtd REQUIRED)
add_sources(README.md src/directory_valid_does_not_exist.cpp)
target_type(TEST_APPLICATION)
