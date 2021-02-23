cmake_minimum_required(VERSION 3.3)

project(diagnostics)
find_package(xtd REQUIRED)

add_projects(
  stack_trace
  stopwatch
)
