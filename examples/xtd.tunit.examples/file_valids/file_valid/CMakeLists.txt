cmake_minimum_required(VERSION 3.20)

project(file_valid)
find_package(xtd REQUIRED)
add_sources(README.md src/file_valid.cpp)
target_type(TEST_APPLICATION)
