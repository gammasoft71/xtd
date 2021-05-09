cmake_minimum_required(VERSION 3.3)

project(others)
find_package(xtd REQUIRED)

add_projects(
  class_with_insert_stream_operator
  class_without_insert_stream_operator
  create_gtest_like_event_listener
  line_info
  many_asserts
  many_valids_and_asserts
  tunit_config_main
)
