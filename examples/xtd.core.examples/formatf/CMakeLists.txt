cmake_minimum_required(VERSION 3.3)

project(formatf)
find_package(xtd REQUIRED)

add_projects(
  formatf
  formatf_boolean
  formatf_character
  formatf_class
  formatf_class_with_specified_formating
  formatf_date_time
  #formatf_duration
  #formatf_enum
  #formatf_enum_class
  formatf_floating_point
  formatf_numeric
  #formatf_string
  #formatf_with_alignment
  #formatf_with_order
)

