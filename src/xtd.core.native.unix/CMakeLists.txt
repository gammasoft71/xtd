cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.core.native.unix)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)
add_references(xtd.core.native)
add_sources(
  include/xtd/xtd.core.native.unix.h
  include/xtd/xtd.core.native.unix
  src/xtd/native/unix/console.cpp
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
