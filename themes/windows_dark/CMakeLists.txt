cmake_minimum_required(VERSION 3.20)

# Project
project(windows_dark)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)

add_sources(
  button.css
  control.css
  flat-button.css
  flat-toggle-button.css
  form.css
  label.css
  link-label.css
  panel.css
  popup-button.css
  popup-toggle-button.css
  system-colors.css
  system-images.css
  theme.css
  toggle-button.css
  user-control.css
)
target_type(INTERFACE_LIBRARY)
