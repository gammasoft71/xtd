cmake_minimum_required(VERSION 3.3)

project(format)
find_package(xtd REQUIRED)

add_projects(
  format
  format_any
  format_associative_containers
  format_boolean
  format_character
  format_class
  format_class_with_specified_formating
  format_date_time
  format_duration
  format_enum
  format_enum_class
  format_exception
  format_floating_point
  format_numeric
  format_nullptr
  format_optional
  format_pair
  format_pointer
  format_sequence_containers
  format_string
  format_tuple
  format_unordered_associative_containers
  format_with_alignment
  format_with_order
)

