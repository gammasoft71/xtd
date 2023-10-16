cmake_minimum_required(VERSION 3.20)

project(parse)
find_package(xtd REQUIRED)

add_projects(
  parse_boolean
  parse_enum
  parse_enum_class
  parse_enum_struct
  parse_floating_point
  parse_numeric
)

