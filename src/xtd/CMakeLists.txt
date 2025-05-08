cmake_minimum_required(VERSION 3.20)

# Project
project(xtd_lib)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
add_include_directories("include")
include("references.cmake")

add_sources(
  "include/xtd/xtd"
  "include/xtd/xtd.hpp"
)
target_name(xtd)
target_type(INTERFACE_LIBRARY)

# Install
add_install_include_directories("include/xtd")
install_component()
