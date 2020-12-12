cmake_minimum_required(VERSION 3.3)

# Project
project(guidgen-gui)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_references(xtd)
add_sources(
  src/main_form.h
)
target_type(GUI_APPLICATION)

# Install
install_component()
