cmake_minimum_required(VERSION 3.20)

project(math_valid)
find_package(xtd REQUIRED)
add_sources(README.md src/math_valid.cpp)
target_type(TEST_APPLICATION)
