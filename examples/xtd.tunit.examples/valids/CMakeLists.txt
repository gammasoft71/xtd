cmake_minimum_required(VERSION 3.3)

project(valids)
find_package(xtd REQUIRED)

add_projects(
  valid
  valid_are_equal
  valid_are_equal_with_tolerance
  valid_are_not_equal
  valid_are_not_same
  valid_are_same
  valid_contains
)
