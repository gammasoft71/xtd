cmake_minimum_required(VERSION 3.20)

project(string_valids)
find_package(xtd REQUIRED)

add_projects(
  string_valid
  string_valid_are_equal_ignoring_case
  string_valid_are_not_equal_ignoring_case
  string_valid_contains
  string_valid_does_not_contain
  string_valid_does_not_end_with
  string_valid_does_not_match
  string_valid_does_not_start_with
  string_valid_ends_with
  string_valid_matches
  string_valid_starts_with
)
