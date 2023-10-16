cmake_minimum_required(VERSION 3.20)

project(valid)
find_package(xtd REQUIRED)
add_sources(README.md src/valid.cpp)
target_type(TEST_APPLICATION)
