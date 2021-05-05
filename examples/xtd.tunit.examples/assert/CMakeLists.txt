cmake_minimum_required(VERSION 3.3)

project(assert)
find_package(xtd REQUIRED)

add_projects(
  assert
  assert_abort
  asser_are_equal
  assert_are_equal_with_tolerence
)
