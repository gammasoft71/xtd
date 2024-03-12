cmake_minimum_required(VERSION 3.20)

project(process)
find_package(xtd REQUIRED)

build_output_directory(${PROJECT_BINARY_DIR})

add_projects(
  hello_world
  process
)

