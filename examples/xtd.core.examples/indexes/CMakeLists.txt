cmake_minimum_required(VERSION 3.20)

project(indexes)
find_package(xtd REQUIRED)

add_projects(
  index
  index_literal
  index_operator
  range
  range_literal
)

