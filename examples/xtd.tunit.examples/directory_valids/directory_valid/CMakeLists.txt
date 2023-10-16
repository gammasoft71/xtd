cmake_minimum_required(VERSION 3.20)

project(directory_valid)
find_package(xtd REQUIRED)
add_sources(README.md src/directory_valid.cpp)
target_type(TEST_APPLICATION)
