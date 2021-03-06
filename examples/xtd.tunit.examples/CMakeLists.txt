cmake_minimum_required(VERSION 3.3)

project(xtd.tunit.examples)
find_package(xtd REQUIRED)

add_projects(
  assert
  assert_abort
  assert_are_equal
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
  class_with_insert_stream_operator
  class_without_insert_stream_operator
  collection_assert_all_items_are_instances_of
  collection_assert_all_items_are_not_null
  console_unit_test
  create_your_own_assertion_class
  create_your_own_event_listener
  generic_test_class
  hello_world_tunit
  line_info
  many_asserts
  many_valids_and_asserts
  ostream_unit_test
  string_assert_are_equal_ignoring_case
  string_assert_are_not_equal_ignoring_case
  string_assert_contains
  test_class
  test_class_without_helpers
  tunit_config_main
)
