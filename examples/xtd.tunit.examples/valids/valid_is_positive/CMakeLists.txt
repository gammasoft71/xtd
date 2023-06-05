cmake_minimum_required(VERSION 3.3)

project(valid_is_positive)
find_package(xtd REQUIRED)
add_sources(README.md src/valid_is_positive.cpp)
target_type(TEST_APPLICATION)
