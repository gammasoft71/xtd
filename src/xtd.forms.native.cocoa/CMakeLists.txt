cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.forms.native.cocoa)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
add_link_options("-framework Cocoa")
add_include_directories("include")
add_references(xtd.drawing xtd.forms.native)
add_sources(
  "include/xtd/xtd.forms.native.cocoa.h"
  "include/xtd/xtd.forms.native.cocoa"
)
add_sources(
  "src/xtd/forms/native/cocoa/forms.cpp"
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories("include/xtd")
install_component()
