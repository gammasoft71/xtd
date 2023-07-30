cmake_minimum_required(VERSION 3.5)

project(exceptions)
find_package(xtd REQUIRED)

add_projects(
  argument_exception
  exception_ptr
  system_exception
)
