cmake_minimum_required(VERSION 3.3)

project(xtd_forms_tutorial)
find_package(xtd.forms REQUIRED)

#build_output_directory("${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE}")

add_projects(
  #tutorial_console
  #tutorial_console_write_line
  #tutorial_environment
  #tutorial_strings
  tutorial_simple_application
  tutorial_application_icon
  tutorial_button
  tutorial_communicate
)
