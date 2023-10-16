cmake_minimum_required(VERSION 3.20)

project(environment)
find_package(xtd REQUIRED)

add_projects(
  environment
  environment_cancel_signal
  environment_command_line
  environment_current_directory
  environment_exit
  environment_exit_code
  environment_expand_environment_variables
  environment_program_exit
  environment_stack_trace
  environment_tick_count
)

