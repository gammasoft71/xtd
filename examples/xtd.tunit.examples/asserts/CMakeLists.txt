cmake_minimum_required(VERSION 3.3)

project(asserts)
find_package(xtd REQUIRED)

add_projects(
  assert
  assert_abort
  asser_are_equal
  assert_are_equal_with_tolerence
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
)
