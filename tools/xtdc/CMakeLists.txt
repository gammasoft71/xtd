cmake_minimum_required(VERSION 3.3)

# Project
project(xtdc)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_sources(
  src/project_language.h
  src/project_management.h
  src/project_sdk.h
  src/project_type.h
  src/xtdc.cpp
)
target_type(CONSOLE_APPLICATION)

# Install
install_component()
