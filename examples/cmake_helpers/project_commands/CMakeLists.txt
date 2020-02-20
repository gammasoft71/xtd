cmake_minimum_required(VERSION 3.3)

# Solution
project(project_commands)
find_package(xtd REQUIRED)

# Projects
add_projects(
  resources_command
  settings_command
)
