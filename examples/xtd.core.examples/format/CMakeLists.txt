cmake_minimum_required(VERSION 3.20)

project(format)
find_package(xtd REQUIRED)

add_projects(
  format
  format_any
  format_associative_containers
  format_boolean
  format_character
  format_class
  format_class_object
  format_class_with_specified_formating
  format_class_with_specified_formating_with_to_string
  format_date_time
  format_duration
  format_enum
  format_enum_class
  format_enum_class_flags
  format_enum_class_flags_without_helper
  format_exception
  format_floating_point
  format_nullptr
  format_number
  format_optional
  format_pair
  format_pointer
  format_sequence_containers
  format_string
  format_system_clock
  format_time_span
  format_tm
  format_tuple
  format_unordered_associative_containers
  format_with_alignment
  format_with_order
)

