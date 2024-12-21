cmake_minimum_required(VERSION 3.20)

project(linq)
find_package(xtd REQUIRED)

add_projects(
  enumerable_aggregate
  enumerable_aggregate2
  enumerable_aggregate3
  enumerable_all
  enumerable_any
)
