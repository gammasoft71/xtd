cmake_minimum_required(VERSION 3.20)

project(file_assumes)
find_package(xtd REQUIRED)

add_projects(
  file_assume
  file_assume_are_equal
  file_assume_are_not_equal
  file_assume_does_not_exist
  file_assume_exists
)
