cmake_minimum_required(VERSION 3.3)

project(directory_asserts)
find_package(xtd REQUIRED)

add_projects(
  directory_assert
  directory_assert_are_equal
  directory_assert_are_not_equal
  directory_assert_exists
)
