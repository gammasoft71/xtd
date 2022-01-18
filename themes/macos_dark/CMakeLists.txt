cmake_minimum_required(VERSION 3.3)

# Project
project(macos_dark)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)

add_sources(
  buttton.css
  control.css
  form.css
  label.css
  system-images.css
  system-colors.css
  theme.css
)
target_type(INTERFACE_LIBRARY)
