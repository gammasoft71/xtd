cmake_minimum_required(VERSION 3.3)

project(console_unit_test)
find_package(xtd REQUIRED)
add_sources(src/console_unit_test.cpp)
target_type(TEST_APPLICATION)
