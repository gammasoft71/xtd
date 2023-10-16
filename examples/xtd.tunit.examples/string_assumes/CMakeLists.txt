cmake_minimum_required(VERSION 3.20)

project(string_assumes)
find_package(xtd REQUIRED)

add_projects(
  string_assume
  string_assume_are_equal_ignoring_case
  string_assume_are_not_equal_ignoring_case
  string_assume_contains
  string_assume_does_not_contain
  string_assume_does_not_end_with
  string_assume_does_not_match
  string_assume_does_not_start_with
  string_assume_ends_with
  string_assume_matches
  string_assume_starts_with
)
