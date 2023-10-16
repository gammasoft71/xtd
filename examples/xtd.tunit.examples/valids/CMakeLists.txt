cmake_minimum_required(VERSION 3.20)

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
  valid_does_not_throw
  valid_is_empty
  valid_is_false
  valid_is_greater
  valid_is_greater_or_equal
  valid_is_instance_of
  valid_is_less
  valid_is_less_or_equal
  valid_is_NaN
  valid_is_negative
  valid_is_not_empty
  valid_is_not_instance_of
  valid_is_not_null
  valid_is_not_zero
  valid_is_null
  valid_is_positive
  valid_is_true
  valid_is_zero
  valid_throws
  valid_throws_any
)
