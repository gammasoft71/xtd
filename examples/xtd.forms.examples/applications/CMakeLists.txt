cmake_minimum_required(VERSION 3.20)

project(applications)
find_package(xtd REQUIRED)

add_projects(
  application
  application_and_assert
  application_and_exception
  application_context
  application_restart
  application_use_wait_cursor
  application_with_cmake_assembly_info
  application_with_manual_assembly_info
)
