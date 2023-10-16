cmake_minimum_required(VERSION 3.20)

project(directory_assume)
find_package(xtd REQUIRED)
add_sources(README.md src/directory_assume.cpp)
target_type(TEST_APPLICATION)
