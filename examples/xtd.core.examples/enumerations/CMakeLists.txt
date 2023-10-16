cmake_minimum_required(VERSION 3.20)

project(enumerations)
find_package(xtd REQUIRED)

add_projects(
  enum
  enum_ut
  enum_class
  enum_class_ut
  enum_class_flags
  enum_class_flags_introspection
  enum_class_flags_without_helpers
  enum_class_parse
  enum_class_without_helper
  enum_struct
  enum_struct_ut
)

