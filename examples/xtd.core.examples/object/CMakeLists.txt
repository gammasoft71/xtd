cmake_minimum_required(VERSION 3.20)

project(object)
find_package(xtd REQUIRED)

add_projects(
  object
  object_equals
  object_equals2
  object_get_type
  object_memberwise_clone
  object_reference_equals
)
