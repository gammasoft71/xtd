cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.forms.native.win32)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
add_include_directories("include")
add_references(xtd.drawing xtd.forms.native)
  "include/xtd/xtd.forms.native.win32.h"
  "include/xtd/xtd.forms.native.win32"
)
add_sources(
  "src/xtd/forms/native/win32/forms.cpp"
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories("include/xtd")
install_component()
