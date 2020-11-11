cmake_minimum_required(VERSION 3.3)

project(many_valids_and_asserts)
find_package(xtd REQUIRED)
add_sources(src/many_valids_and_asserts.cpp)
target_type(TEST_APPLICATION)
