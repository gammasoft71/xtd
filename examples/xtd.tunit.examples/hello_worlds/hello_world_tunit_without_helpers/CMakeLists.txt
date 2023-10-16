cmake_minimum_required(VERSION 3.20)

project(hello_world_tunit_without_helpers)
find_package(xtd REQUIRED)
add_sources(README.md src/hello_world_tunit_without_helpers.cpp)
target_type(TEST_APPLICATION)
