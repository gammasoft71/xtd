cmake_minimum_required(VERSION 3.20)

# Solution
project(tools)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

# Add projects
add_projects(
  guidgen
  guidgen-gui
  keycodes
  sleepfor
  set_environment_variable
  set_path
  xtdc
  xtdc-gui
)
