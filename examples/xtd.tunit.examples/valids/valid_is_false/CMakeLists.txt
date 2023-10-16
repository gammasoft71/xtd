cmake_minimum_required(VERSION 3.20)

project(valid_is_false)
find_package(xtd REQUIRED)
add_sources(README.md src/valid_is_false.cpp)
target_type(TEST_APPLICATION)
