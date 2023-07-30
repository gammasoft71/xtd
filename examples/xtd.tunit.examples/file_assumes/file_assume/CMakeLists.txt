cmake_minimum_required(VERSION 3.5)

project(file_assume)
find_package(xtd REQUIRED)
add_sources(README.md src/file_assume.cpp)
target_type(TEST_APPLICATION)
