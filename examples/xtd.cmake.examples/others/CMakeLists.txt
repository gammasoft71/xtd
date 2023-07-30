cmake_minimum_required(VERSION 3.5)

# Solution
project(other)
find_package(xtd REQUIRED)

# Projects
add_projects(
  console_application
  gui_application
  test_application
)
