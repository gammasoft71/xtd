cmake_minimum_required(VERSION 3.3)

project(xtd.core.examples)
find_package(xtd REQUIRED)

add_projects(
  block_scope
  compare
  compare_ignore_case
  concat
  concat_collection
  contains
  delegate
  environment_stack_trace
  event
  format
  format_with_order
  guid
  interface
  interface2
  join
  main
  main1
  main2
  main3
  main4
  main5
  split
  startup
  static
  static2
  static3
  using
)

add_projects(
  console
  diagnostics
  hello_worlds
  others
)

