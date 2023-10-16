cmake_minimum_required(VERSION 3.20)

project(collection_valids)
find_package(xtd REQUIRED)

add_projects(
  collection_valid
  collection_valid_all_items_are_instances_of
  collection_valid_all_items_are_not_null
  collection_valid_all_items_are_unique
  collection_valid_are_equal
  collection_valid_are_equivalent
  collection_valid_are_not_equal
  collection_valid_are_not_equivalent
  collection_valid_contains
  collection_valid_does_not_contain
  collection_valid_is_empty
  collection_valid_is_not_empty
  collection_valid_is_ordered
)
