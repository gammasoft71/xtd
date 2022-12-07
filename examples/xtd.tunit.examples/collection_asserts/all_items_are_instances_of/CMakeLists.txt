cmake_minimum_required(VERSION 3.3)

project(all_items_are_instances_of)
find_package(xtd REQUIRED)
add_sources(src/all_items_are_instances_of.cpp)
target_type(TEST_APPLICATION)
