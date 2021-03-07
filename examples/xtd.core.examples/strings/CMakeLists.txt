cmake_minimum_required(VERSION 3.3)

project(strings)
find_package(xtd REQUIRED)

add_projects(
  compare
  compare_ignore_case
  concat
  concat_collection
  contains
  join
  split
  string_format
  string_format_with_order
  string_unicode
)
