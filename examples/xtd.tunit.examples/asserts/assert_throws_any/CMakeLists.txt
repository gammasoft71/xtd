cmake_minimum_required(VERSION 3.20)

project(assert_throws_any)
find_package(xtd REQUIRED)
add_sources(README.md src/assert_throws_any.cpp)
target_type(TEST_APPLICATION)
