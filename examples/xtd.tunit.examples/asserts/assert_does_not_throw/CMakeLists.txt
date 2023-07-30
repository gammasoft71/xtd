cmake_minimum_required(VERSION 3.5)

project(assert_does_not_throw)
find_package(xtd REQUIRED)
add_sources(README.md src/assert_does_not_throw.cpp)
target_type(TEST_APPLICATION)
