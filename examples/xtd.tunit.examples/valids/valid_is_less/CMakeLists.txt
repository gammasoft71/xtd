cmake_minimum_required(VERSION 3.20)

project(valid_is_less)
find_package(xtd REQUIRED)
add_sources(README.md src/valid_is_less.cpp)
target_type(TEST_APPLICATION)
