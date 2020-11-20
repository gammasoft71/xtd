cmake_minimum_required(VERSION 3.3)

project(hello_worlds)
find_package(xtd REQUIRED)

add_projects(
  hello_world_console
  hello_world_diagnostics
  hello_world_environment
  hello_world_io
  hello_world_strings
)
