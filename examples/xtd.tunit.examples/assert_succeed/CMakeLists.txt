cmake_minimum_required(VERSION 3.3)

project(assert_succeed)
find_package(xtd REQUIRED)
add_sources(src/assert_succeed.cpp)
target_type(TEST_APPLICATION)
