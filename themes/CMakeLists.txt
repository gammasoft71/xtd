cmake_minimum_required(VERSION 3.20)

# Project
project(themes)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

# Projects
add_projects(
  default 
  gnome_dark 
  gnome_light
  kde_dark 
  kde_light
  macos_dark
  macos_light
  symbolic_dark
  symbolic_light
  windows_dark
  windows_light
  xtd_dark
  xtd_light
)
