cmake_minimum_required(VERSION 3.20)

project(directory_valids)
find_package(xtd REQUIRED)

add_projects(
  directory_valid
  directory_valid_are_equal
  directory_valid_are_not_equal
  directory_valid_does_not_exist
  directory_valid_exists
)
