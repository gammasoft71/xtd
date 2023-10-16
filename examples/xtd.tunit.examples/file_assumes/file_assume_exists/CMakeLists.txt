cmake_minimum_required(VERSION 3.20)

project(file_assume_exists)
find_package(xtd REQUIRED)
add_sources(README.md src/file_assume_exists.cpp)
target_type(TEST_APPLICATION)
