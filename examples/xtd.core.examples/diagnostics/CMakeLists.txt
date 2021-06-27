cmake_minimum_required(VERSION 3.3)

project(diagnostics)
find_package(xtd REQUIRED)

add_projects(
  assert_
  assert_with_message
  console_trace_listener
  debug_cassert
  default_trace_listener
  stack_frame
  stack_trace
  stack_trace_simple
  stopwatch
  stopwatch_constructor
  trace_cassert
)
