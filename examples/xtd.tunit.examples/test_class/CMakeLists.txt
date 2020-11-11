cmake_minimum_required(VERSION 3.3)

project(test_class)
find_package(xtd REQUIRED)
add_sources(src/test_class.cpp)
target_type(TEST_APPLICATION)
