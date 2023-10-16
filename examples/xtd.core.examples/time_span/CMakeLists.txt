cmake_minimum_required(VERSION 3.20)

project(time_span)
find_package(xtd REQUIRED)

add_projects(
  time_span
  time_span_from_days
  time_span_from_hours
)

