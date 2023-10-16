cmake_minimum_required(VERSION 3.20)

project(test_class_without_helpers)
find_package(xtd REQUIRED)
add_sources(README.md src/test_class_without_helpers.cpp)
target_type(TEST_APPLICATION)
