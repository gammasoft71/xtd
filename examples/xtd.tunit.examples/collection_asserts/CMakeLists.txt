cmake_minimum_required(VERSION 3.20)

project(collection_asserts)
find_package(xtd REQUIRED)

add_projects(
  collection_assert
  collection_assert_all_items_are_instances_of
  collection_assert_all_items_are_not_null
  collection_assert_all_items_are_unique
  collection_assert_are_equal
  collection_assert_are_equivalent
  collection_assert_are_not_equal
  collection_assert_are_not_equivalent
  collection_assert_contains
  collection_assert_does_not_contain
  collection_assert_is_empty
  collection_assert_is_not_empty
  collection_assert_is_ordered
)
