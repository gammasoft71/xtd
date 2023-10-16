cmake_minimum_required(VERSION 3.20)

# Project
project(xtd)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)
include(references.cmake)

add_sources(
  include/xtd/xtd
  include/xtd/xtd
  include/xtd/xtd.h
  include/xtd/system_report.h
  include/xtd/system_report
  src/xtd/system_report.cpp
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
