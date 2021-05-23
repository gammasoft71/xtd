cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.core.native.win32)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)
add_references(rpcrt4)
add_references(xtd.core.native)
add_sources(
  include/xtd/xtd.core.native.win32.h
  include/xtd/xtd.core.native.win32
  src/xtd/native/win32/console.cpp
  src/xtd/native/win32/debug.cpp
  src/xtd/native/win32/environment.cpp
  src/xtd/native/win32/file.cpp
  src/xtd/native/win32/guid.cpp
  src/xtd/native/win32/path.cpp
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
