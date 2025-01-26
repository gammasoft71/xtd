cmake_minimum_required(VERSION 3.20)

project(span)
find_package(xtd REQUIRED)

add_projects(
  span_from_memory
  span_over_array
)

