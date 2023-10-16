cmake_minimum_required(VERSION 3.20)

project(keywords)
find_package(xtd REQUIRED)

add_projects(
  block_scope
  current_stack_frame
  csf
  interface
  interface2
  lock
  lock_guard_keyword
  startup_keyword
  static
  static_object
  static_object2
  using
)
