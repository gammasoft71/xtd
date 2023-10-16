cmake_minimum_required(VERSION 3.20)

project(directory_assumes)
find_package(xtd REQUIRED)

add_projects(
  directory_assume
  directory_assume_are_equal
  directory_assume_are_not_equal
  directory_assume_does_not_exist
  directory_assume_exists
)
