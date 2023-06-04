cmake_minimum_required(VERSION 3.3)

project(valids)
find_package(xtd REQUIRED)

add_projects(
  valid
  valid_are_equal
  valid_are_equal_with_tolerance
)
