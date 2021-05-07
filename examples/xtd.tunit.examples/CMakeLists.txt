cmake_minimum_required(VERSION 3.3)

project(xtd.tunit.examples)
find_package(xtd REQUIRED)

add_projects(
  asserts
  collection_asserts
  create_your_own_event_listener
  generic_test_class
  hello_worlds
  string_asserts
  test_class
  test_class_without_helpers
  unit_tests
  user_asserts
)
