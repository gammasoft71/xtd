cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd.cmake.xamples)
find_package(xtd REQUIRED)

# Projects
add_projects(
  hello_worlds
  target_properties
  assembly_informations
  build_options
  project_commands
  others
)
