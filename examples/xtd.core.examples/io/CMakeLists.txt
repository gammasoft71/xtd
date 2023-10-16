cmake_minimum_required(VERSION 3.20)

project(io)
find_package(xtd REQUIRED)

add_projects(
  binary_reader
  binary_reader2
  directory_info
  drive_info
  file_info
  file_info2
  file_info_append_text
  file_info_move_to
  file_info_open
  file_info_open_read
  file_info_open_text
  file_info_open_write
  file_info_replace
)
