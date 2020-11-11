cmake_minimum_required(VERSION 3.3)

project(many_asserts)
find_package(xtd REQUIRED)
add_sources(src/many_asserts.cpp)
target_type(TEST_APPLICATION)
