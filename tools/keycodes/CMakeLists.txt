cmake_minimum_required(VERSION 3.20)

# Project
project(keycodes)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_sources(
  src/key_control.hpp
  src/key_control.cpp
  src/key_press_control.hpp
  src/key_press_control.cpp
  src/main_form.hpp
  src/main_form.cpp
)
target_type(GUI_APPLICATION)

# Install
install_component()
