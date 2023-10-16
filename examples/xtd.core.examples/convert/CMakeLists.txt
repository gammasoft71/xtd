cmake_minimum_required(VERSION 3.20)

project(convert)
find_package(xtd REQUIRED)

add_projects(
  as
  to_byte
  to_int32
  to_ustring
)

