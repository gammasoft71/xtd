cmake_minimum_required(VERSION 3.3)

project(collection_assert_all_items_are_not_null)
find_package(xtd REQUIRED)
add_sources(src/collection_assert_all_items_are_not_null.cpp)
target_type(TEST_APPLICATION)
