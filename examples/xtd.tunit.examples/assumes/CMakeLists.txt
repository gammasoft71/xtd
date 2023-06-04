cmake_minimum_required(VERSION 3.3)

project(assumes)
find_package(xtd REQUIRED)

add_projects(
  assume
  assume_are_equal
  assume_are_equal_with_tolerance
  assume_are_not_equal
  assume_are_not_same
  assume_are_same
  assume_contains
  assume_does_not_throw
  assume_is_empty
  assume_is_false
  assume_is_greater
  assume_is_greater_or_equal
  assume_is_instance_of
  assume_is_less
  assume_is_less_or_equal
)
