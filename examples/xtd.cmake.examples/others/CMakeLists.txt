cmake_minimum_required(VERSION 3.3)

# Solution
project(other)
find_package(xtd REQUIRED)

# Projects
add_projects(
  console_application
  gui_application
  test_application
)
