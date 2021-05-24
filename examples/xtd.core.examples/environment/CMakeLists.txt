cmake_minimum_required(VERSION 3.3)

project(environment)
find_package(xtd REQUIRED)

add_projects(
  environment_stack_trace
  environment_tick_count
)

