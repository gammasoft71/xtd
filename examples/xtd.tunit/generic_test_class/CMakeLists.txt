cmake_minimum_required(VERSION 3.3)

project(generic_test_class)
find_package(xtd REQUIRED)
add_sources(src/generic_test_class.cpp)
target_type(TEST_APPLICATION)
