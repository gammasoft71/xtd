cmake_minimum_required(VERSION 3.20)

project(asserts)
find_package(xtd REQUIRED)

add_projects(
  assert
  assert_abort
  assert_are_equal
  assert_are_equal_with_tolerance
  assert_are_not_equal
  assert_are_not_same
  assert_are_same
  assert_contains
  assert_does_not_throw
  assert_fail
  assert_ignore
  assert_is_NaN
  assert_is_empty
  assert_is_false
  assert_is_greater
  assert_is_greater_or_equal
  assert_is_instance_of
  assert_is_less
  assert_is_less_or_equal
  assert_is_negative
  assert_is_not_empty
  assert_is_not_instance_of
  assert_is_not_null
  assert_is_not_zero
  assert_is_null
  assert_is_positive
  assert_is_true
  assert_is_zero
  assert_succeed
  assert_throws
  assert_throws_any
)
