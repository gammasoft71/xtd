cmake_minimum_required(VERSION 3.20)

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
  assume_is_NaN
  assume_is_negative
  assume_is_not_empty
  assume_is_not_instance_of
  assume_is_not_null
  assume_is_not_zero
  assume_is_null
  assume_is_positive
  assume_is_true
  assume_is_zero
  assume_throws
  assume_throws_any
)
