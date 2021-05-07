cmake_minimum_required(VERSION 3.3)

project(collection_asserts)
find_package(xtd REQUIRED)

add_projects(
  collection_assert_all_items_are_instances_of
  collection_assert_all_items_are_not_null
)
