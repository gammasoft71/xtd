cmake_minimum_required(VERSION 3.3)

# Project
project(xtd)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)
include(references.cmake)
add_sources(
  include/xtd/xtd
  include/xtd/cmake_page.h
  include/xtd/format_page.h
  include/xtd/main_page.h
  include/xtd/system_report.h
  include/xtd/xtd.h
  include/xtd/xtd.h
  src/xtd/system_report.cpp
  references.cmake
  ../../locale/en/about_dialog.strings
  ../../locale/en/application.strings
  ../../locale/en/busy_box.strings
  ../../locale/en/checked_list_box.strings
  ../../locale/en/exceptions.strings
  ../../scripts/cmake/update_export.cmake
  ../../scripts/cmake/update_version_number.cmake
  ../../scripts/cmake/xtd_commands.cmake
  ../../scripts/cmake/xtd_version.cmake
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
