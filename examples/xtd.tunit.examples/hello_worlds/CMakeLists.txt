cmake_minimum_required(VERSION 3.20)

project(hello_worlds)
find_package(xtd REQUIRED)

add_projects(
  hello_world_tunit
  hello_world_tunit_without_helpers
)
