cmake_minimum_required(VERSION 3.20)

project(directory_asserts)
find_package(xtd REQUIRED)

add_projects(
  directory_assert
  directory_assert_are_equal
  directory_assert_are_not_equal
  directory_assert_does_not_exist
  directory_assert_exists
)
