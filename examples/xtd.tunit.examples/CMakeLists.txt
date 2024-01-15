cmake_minimum_required(VERSION 3.20)

project(xtd.tunit.examples)
find_package(xtd REQUIRED)

add_projects(
  asserts
  assumes
  collection_asserts
  collection_assumes
  collection_valids
  directory_asserts
  directory_assumes
  directory_valids
  file_asserts
  file_assumes
  file_valids
  hello_worlds
  others
  string_asserts
  string_assumes
  string_valids
  test_classes
  unit_tests
  user_asserts
  user_assumes
  user_valids
  valids
  tests
)
