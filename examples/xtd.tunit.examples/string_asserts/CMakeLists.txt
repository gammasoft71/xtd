cmake_minimum_required(VERSION 3.20)

project(string_asserts)
find_package(xtd REQUIRED)

add_projects(
  string_assert
  string_assert_are_equal_ignoring_case
  string_assert_are_not_equal_ignoring_case
  string_assert_contains
  string_assert_does_not_contain
  string_assert_does_not_end_with
  string_assert_does_not_match
  string_assert_does_not_start_with
  string_assert_ends_with
  string_assert_matches
  string_assert_starts_with
)
