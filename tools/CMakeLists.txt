cmake_minimum_required(VERSION 3.5)

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
  set_path
  xtdc
  xtdc-gui
)
