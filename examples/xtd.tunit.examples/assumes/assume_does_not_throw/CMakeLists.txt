cmake_minimum_required(VERSION 3.20)

project(assume_does_not_throw)
find_package(xtd REQUIRED)
add_sources(README.md src/assume_does_not_throw.cpp)
target_type(TEST_APPLICATION)
