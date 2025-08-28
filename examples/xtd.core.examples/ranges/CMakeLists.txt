cmake_minimum_required(VERSION 3.20)

project(ranges)
find_package(xtd REQUIRED)

add_projects(
  ranges_views_distinct
  ranges_views_distinct2
  ranges_views_select
  ranges_views_select2
)
