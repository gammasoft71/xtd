cmake_minimum_required(VERSION 3.3)

project(assumes)
find_package(xtd REQUIRED)

add_projects(
  assume
  assume_are_equal
  assume_are_equal_with_tolerance
  assume_are_not_equal
)
