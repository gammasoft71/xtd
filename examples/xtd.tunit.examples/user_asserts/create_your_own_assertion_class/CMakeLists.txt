cmake_minimum_required(VERSION 3.3)

project(create_your_own_assertion_class)
find_package(xtd REQUIRED)
add_sources(src/create_your_own_assertion_class.cpp)
target_type(TEST_APPLICATION)
