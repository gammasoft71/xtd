cmake_minimum_required(VERSION 3.3)

project(format)
find_package(xtd REQUIRED)

add_projects(
  format
  format_boolean
  format_character
  format_class
  format_class_with_specified_formating
  format_date_time
  format_duration
  format_enum
  format_enum_class
  format_floating_point
  format_numeric
  format_string
  format_with_alignment
  format_with_order
)

