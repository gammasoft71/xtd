cmake_minimum_required(VERSION 3.20)

project(file_valids)
find_package(xtd REQUIRED)

add_projects(
  file_valid
  file_valid_are_equal
  file_valid_are_not_equal
  file_valid_does_not_exist
  file_valid_exists
)
