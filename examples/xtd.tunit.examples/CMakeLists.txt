cmake_minimum_required(VERSION 3.3)

project(xtd.tunit.examples)
find_package(xtd REQUIRED)

add_projects(
  asserts
  assumes
  collection_asserts
  expects
  hello_worlds
  others
  string_asserts
  test_classes
  unit_tests
  user_asserts
  valids
)
