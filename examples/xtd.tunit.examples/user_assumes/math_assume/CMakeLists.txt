cmake_minimum_required(VERSION 3.20)

project(math_assume)
find_package(xtd REQUIRED)
add_sources(README.md src/math_assume.cpp)
target_type(TEST_APPLICATION)
