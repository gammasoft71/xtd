cmake_minimum_required(VERSION 3.3)

project(assert_does_not_throw)
find_package(xtd REQUIRED)
add_sources(src/assert_does_not_throw.cpp)
target_type(TEST_APPLICATION)
