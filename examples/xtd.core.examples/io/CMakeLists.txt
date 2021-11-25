cmake_minimum_required(VERSION 3.3)

project(io)
find_package(xtd REQUIRED)

add_projects(
  directory_info
  drive_info
  file_info
)
