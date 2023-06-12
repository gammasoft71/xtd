cmake_minimum_required(VERSION 3.3)

project(directory_valid_exists)
find_package(xtd REQUIRED)
add_sources(README.md src/directory_valid_exists.cpp)
target_type(TEST_APPLICATION)
