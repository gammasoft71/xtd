cmake_minimum_required(VERSION 3.3)

project(assert_abort)
find_package(xtd REQUIRED)
add_sources(src/assert_abort.cpp)
target_type(TEST_APPLICATION)
