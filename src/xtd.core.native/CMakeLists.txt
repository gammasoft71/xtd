cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.core.native)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)
add_sources(
  include/xtd/xtd.core.native
  include/xtd/xtd.core.native.h
  include/xtd/native/console.h
  include/xtd/native/console_color.h
  include/xtd/native/console_special_key.h
)
target_type(INTERFACE_LIBRARY)

# Install
add_install_include_directories(include/xtd)
install_component()
