cmake_minimum_required(VERSION 3.3)

project(assert)
find_package(xtd REQUIRED)
add_sources(src/assert.cpp)
target_type(TEST_APPLICATION)
