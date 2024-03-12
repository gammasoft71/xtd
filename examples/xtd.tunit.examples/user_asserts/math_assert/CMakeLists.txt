cmake_minimum_required(VERSION 3.20)

project(math_assert)
find_package(xtd REQUIRED)
add_sources(src/math_assert.cpp)
target_type(TEST_APPLICATION)
