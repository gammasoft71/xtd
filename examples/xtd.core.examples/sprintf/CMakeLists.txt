cmake_minimum_required(VERSION 3.20)

project(sprintf)
find_package(xtd REQUIRED)

add_projects(
  sprintf
  sprintf_boolean
  sprintf_character
  sprintf_class
  sprintf_class_with_specified_formating
  sprintf_class_with_specified_formating_with_to_string
  sprintf_date_time
  sprintf_duration
  sprintf_enum
  sprintf_enum_class
  sprintf_floating_point
  sprintf_numeric
  sprintf_string
  sprintf_with_alignment
)

