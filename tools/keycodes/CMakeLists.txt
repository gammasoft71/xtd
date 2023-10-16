cmake_minimum_required(VERSION 3.20)

# Project
project(keycodes)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_references(xtd)
add_sources(
  src/key_control.h
  src/key_control.cpp
  src/key_press_control.h
  src/key_press_control.cpp
  src/main_form.h
  src/main_form.cpp
)
target_type(GUI_APPLICATION)

# Install
install_component()
