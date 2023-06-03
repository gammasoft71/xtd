cmake_minimum_required(VERSION 3.3)

project(assume)
find_package(xtd REQUIRED)
add_sources(README.md src/assume.cpp)
target_type(TEST_APPLICATION)
