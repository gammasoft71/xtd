cmake_minimum_required(VERSION 3.20)

project(interfaces)
find_package(xtd REQUIRED)

add_projects(
  iasync_result
  iclonable
  icomparable
  iequatable
  iformatable
  iformatable_vs_to_string
  iobservable_iobserver
  iprogress
)

