cmake_minimum_required(VERSION 3.3)

project(environment)
find_package(xtd REQUIRED)

add_projects(
  environment_command_line
  environment_current_directory
  environment_exit_code
  environment_expand_environment_variables
  environment_stack_trace
  environment_tick_count
)

