cmake_minimum_required(VERSION 3.3)

project(valid_is_not_empty)
find_package(xtd REQUIRED)
add_sources(README.md src/valid_is_not_empty.cpp)
target_type(TEST_APPLICATION)
