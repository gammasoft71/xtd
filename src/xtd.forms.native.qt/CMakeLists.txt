cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.forms.native.qt)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()
add_include_directories("include")
add_references(xtd.drawing xtd.forms.native Qt6::Widgets)
add_sources(
  "include/xtd/xtd.forms.native.qt.h"
  "include/xtd/xtd.forms.native.qt"
add_sources(
  "src/xtd/forms/native/qt/forms.cpp"
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories("include/xtd")
install_component()
