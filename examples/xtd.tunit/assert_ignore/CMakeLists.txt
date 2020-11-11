cmake_minimum_required(VERSION 3.3)

project(assert_ignore)
find_package(xtd REQUIRED)
add_sources(src/assert_ignore.cpp)
target_type(TEST_APPLICATION)
