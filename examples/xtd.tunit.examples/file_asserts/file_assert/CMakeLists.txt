cmake_minimum_required(VERSION 3.3)

project(file_assert)
find_package(xtd REQUIRED)
add_sources(README.md src/file_assert.cpp)
target_type(TEST_APPLICATION)
