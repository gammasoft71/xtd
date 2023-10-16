cmake_minimum_required(VERSION 3.20)

project(directory_assert_does_not_exist)
find_package(xtd REQUIRED)
add_sources(README.md src/directory_assert_does_not_exist.cpp)
target_type(TEST_APPLICATION)
