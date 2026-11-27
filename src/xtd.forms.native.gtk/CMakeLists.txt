cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.forms.native.gtk)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)
add_include_directories(${GTK_INCLUDE_DIRS})
add_reference_directories(${GTK_LIBRARY_DIRS})
add_references(${GTK_LIBRARIES})

add_include_directories("include")
add_references(xtd.drawing xtd.drawing.native)

add_sources(
  "include/xtd/xtd.forms.native.gtk.h"
  "include/xtd/xtd.forms.native.gtk"
)
add_sources(
  "src/xtd/forms/native/gtk/forms.cpp"
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories("include/xtd")
install_component()
