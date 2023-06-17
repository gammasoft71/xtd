cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.3rdparty.StackWalker)
include("../../scripts/cmake/xtd_commands.cmake")
add_include_directories(.)
add_sources(
  StackWalker.cpp
  StackWalker.h
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(.)
install_component()
