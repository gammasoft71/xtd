cmake_minimum_required(VERSION 3.20)

project(test_tunit)
find_package(xtd REQUIRED)
add_sources(README.md src/test_tunit.cpp)
target_type(TEST_APPLICATION)
