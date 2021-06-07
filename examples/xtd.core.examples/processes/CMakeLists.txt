cmake_minimum_required(VERSION 3.3)

project(processes)
find_package(xtd REQUIRED)

add_projects(
  process
  process_start_info
  process_with_sandard_output_redirection
)

