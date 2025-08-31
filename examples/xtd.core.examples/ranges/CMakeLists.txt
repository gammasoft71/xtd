cmake_minimum_required(VERSION 3.20)

project(ranges)
find_package(xtd REQUIRED)

add_projects(
  ranges_views_distinct
  ranges_views_distinct2
  ranges_views_order_by
  ranges_views_order_by2
  ranges_views_select
  ranges_views_select2
  ranges_views_where
  ranges_views_where2
)
