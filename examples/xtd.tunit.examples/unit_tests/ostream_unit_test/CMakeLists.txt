cmake_minimum_required(VERSION 3.20)

project(ostream_unit_test)
find_package(xtd REQUIRED)
add_sources(README.md src/ostream_unit_test.cpp)
target_type(TEST_APPLICATION)
