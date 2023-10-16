cmake_minimum_required(VERSION 3.20)

project(valid_does_not_throw)
find_package(xtd REQUIRED)
add_sources(README.md src/valid_does_not_throw.cpp)
target_type(TEST_APPLICATION)
