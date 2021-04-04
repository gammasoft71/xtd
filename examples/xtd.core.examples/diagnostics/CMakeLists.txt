cmake_minimum_required(VERSION 3.3)

project(diagnostics)
find_package(xtd REQUIRED)

add_projects(
  console_trace_listener
  stack_trace
  stopwatch
)
