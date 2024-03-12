cmake_minimum_required(VERSION 3.20)

project(exceptions)
find_package(xtd REQUIRED)

add_projects(
  argument_exception
  exception_ptr
  system_exception
)
