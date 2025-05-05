cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.forms.native.gtk3)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
find_package(PkgConfig)
pkg_check_modules(GTK gtk+-3.0)
add_include_directories(${GTK_INCLUDE_DIRS})
add_reference_directories(${GTK_LIBRARY_DIRS})
add_references(${GTK_LIBRARIES})

add_include_directories("include")
add_references(xtd.drawing xtd.forms.native)

add_sources(
  "include/xtd/xtd.forms.native.gtk3.h"
  "include/xtd/xtd.forms.native.gtk3"
)
add_sources(
  "src/xtd/forms/native/gtk3/forms.cpp"
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories("include/xtd")
install_component()
