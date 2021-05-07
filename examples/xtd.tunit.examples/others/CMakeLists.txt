cmake_minimum_required(VERSION 3.3)

project(others)
find_package(xtd REQUIRED)

add_projects(
  class_with_insert_stream_operator
  class_without_insert_stream_operator
  many_asserts
  many_valids_and_asserts
)
