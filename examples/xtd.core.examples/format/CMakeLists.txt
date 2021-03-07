cmake_minimum_required(VERSION 3.3)

project(format)
find_package(xtd REQUIRED)

add_projects(
  format
  format_class
  format_enum_class
  format_with_order
  formatf
)

