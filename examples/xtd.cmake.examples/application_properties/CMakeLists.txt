cmake_minimum_required(VERSION 3.3)

# Solution
project(application_properties)
find_package(xtd REQUIRED)

# Projects
add_projects(
  application_default_namespace
  application_display
  application_icon
  application_name
  application_registered
  application_startup
  target_type
)
