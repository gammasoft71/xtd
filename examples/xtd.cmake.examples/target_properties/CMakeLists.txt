cmake_minimum_required(VERSION 3.3)

# Solution
project(target_properties)
find_package(xtd REQUIRED)

# Projects
add_projects(
  target_default_namespace
  target_display
  target_icon
  target_name
  target_registered
  target_startup
  target_type
)
