cmake_minimum_required(VERSION 3.20)

project(keywords)
find_package(xtd REQUIRED)

add_projects(
  block_scope
  call_once
  call_once2
  interface
  interface2
  lock
  lock_guard_keyword
  nameof
  sizeof
  startup_keyword
  static
  static_object
  static_object2
  typeof
  using
)
