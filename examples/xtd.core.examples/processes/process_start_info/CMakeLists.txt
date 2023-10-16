cmake_minimum_required(VERSION 3.20)

project(process_start_info)
find_package(xtd REQUIRED)

build_output_directory(${PROJECT_BINARY_DIR})

add_projects(
  args_echo
  start_args_echo
)

