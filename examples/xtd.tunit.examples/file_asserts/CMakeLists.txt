cmake_minimum_required(VERSION 3.20)

project(file_asserts)
find_package(xtd REQUIRED)

add_projects(
  file_assert
  file_assert_are_equal
  file_assert_are_not_equal
  file_assert_does_not_exist
  file_assert_exists
)
