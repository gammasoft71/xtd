cmake_minimum_required(VERSION 3.3)

project(format)
find_package(xtd REQUIRED)

add_projects(
  format
  format_class
  format_class_with_specified_formating
  format_double
  format_duration
  format_enum_class
  format_int
  format_with_alignment
  format_with_order
  formatf
)

