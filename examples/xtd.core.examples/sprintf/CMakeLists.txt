cmake_minimum_required(VERSION 3.3)

project(sprintf)
find_package(xtd REQUIRED)

add_projects(
  sprintf
  sprintf_boolean
  sprintf_character
  sprintf_class
  sprintf_class_with_specified_formating
  sprintf_date_time
  #sprintff_duration
  #sprintf_enum
  #sprintf_enum_class
  sprintf_floating_point
  sprintf_numeric
  #sprintf_string
  #sprintf_with_alignment
  #sprintf_with_order
)

