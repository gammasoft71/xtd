cmake_minimum_required(VERSION 3.3)

# Project
project(guidgen-gui)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_sources(
  src/main_form.cpp
)
target_type(GUI_APPLICATION)

# Install
install_component()
