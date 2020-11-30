cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.drawing.native.gtk4)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
find_package(PkgConfig)
pkg_check_modules(GTK gtk+-3.0)
include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})
add_include_directories(include)
add_references(xtd.core xtd.drawing.native ${GTK_LIBRARIES})
add_sources(
  include/xtd/xtd.drawing.native.gtk4.h
  include/xtd/xtd.drawing.native.gtk4
  src/xtd/drawing/native/gtk4/drawing.cpp
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
