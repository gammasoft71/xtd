cmake_minimum_required(VERSION 3.20)

project(linq)
find_package(xtd REQUIRED)

add_projects(
  enumerable_aggregate
  enumerable_aggregate2
  enumerable_aggregate3
  enumerable_aggregate4
  enumerable_aggregate5
  enumerable_aggregate6
  enumerable_all
  enumerable_all2
  enumerable_any
  enumerable_any2
  enumerable_any3
  enumerable_any4
  enumerable_append
  enumerable_append2
  enumerable_count
  enumerable_count2
  enumerable_count_by
  enumerable_range
  enumerable_select
  enumerable_select2
  enumerable_to_list
  enumerable_where
  enumerable_where2
)
