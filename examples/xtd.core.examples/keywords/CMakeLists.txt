cmake_minimum_required(VERSION 3.3)

project(keywords)
find_package(xtd REQUIRED)

add_projects(
  assert_
  assert_with_message
  block_scope
  current_stack_frame
  csf
  interface
  interface2
  startup
  static
  static_class
  static_class2
  using
)
