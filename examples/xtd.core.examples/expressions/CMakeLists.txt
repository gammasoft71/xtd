cmake_minimum_required(VERSION 3.20)

project(expressions)
find_package(xtd REQUIRED)

add_projects(
  add_expression
  add_expression_with_own_struct
  and_expression
  division_expression
  division_expression_with_own_struct
)
