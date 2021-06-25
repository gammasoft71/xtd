cmake_minimum_required(VERSION 3.3)

project(applications)
find_package(xtd REQUIRED)

add_projects(
  application
  application_and_assert
  application_and_exception
  application_context
  application_enable_dark_mode
  application_enable_light_mode
  application_restart
  application_use_wait_cursor
)
