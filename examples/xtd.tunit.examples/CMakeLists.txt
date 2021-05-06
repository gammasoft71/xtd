cmake_minimum_required(VERSION 3.3)

project(xtd.tunit.examples)
find_package(xtd REQUIRED)

add_projects(
  asserts
  class_with_insert_stream_operator
  class_without_insert_stream_operator
  collection_assert_all_items_are_instances_of
  collection_assert_all_items_are_not_null
  console_unit_test
  create_your_own_assertion_class
  create_your_own_event_listener
  generic_test_class
  hello_worlds
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
  assert_is_not_instance_of
)
