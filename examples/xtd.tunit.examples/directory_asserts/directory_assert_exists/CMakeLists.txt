cmake_minimum_required(VERSION 3.3)

project(directory_assert_exists)
find_package(xtd REQUIRED)
add_sources(README.md src/directory_assert_exists.cpp)
target_type(TEST_APPLICATION)
