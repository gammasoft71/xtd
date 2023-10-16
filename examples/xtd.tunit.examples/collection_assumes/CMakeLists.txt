cmake_minimum_required(VERSION 3.20)

project(collection_assumes)
find_package(xtd REQUIRED)

add_projects(
  collection_assume
  collection_assume_all_items_are_instances_of
  collection_assume_all_items_are_not_null
  collection_assume_all_items_are_unique
  collection_assume_are_equal
  collection_assume_are_equivalent
  collection_assume_are_not_equal
  collection_assume_are_not_equivalent
  collection_assume_contains
  collection_assume_does_not_contain
  collection_assume_is_empty
  collection_assume_is_not_empty
  collection_assume_is_ordered
)
