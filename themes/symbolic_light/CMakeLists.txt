cmake_minimum_required(VERSION 3.20)

# Project
project(symbolic_light)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)

add_sources(
  form.css
  system-colors.css
  theme.css
)
target_type(INTERFACE_LIBRARY)
