cmake_minimum_required(VERSION 3.3)

# Project
project(macos_light)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)

add_sources(
  button-default.css
  button-flat-default.css
  button-flat.css
  button-popup-default.css
  button-popup.css
  button.css
  control.css
  form.css
  label.css
  panel.css
  system-colors.css
  system-images.css
  theme.css
  user-control.css
)
target_type(INTERFACE_LIBRARY)
