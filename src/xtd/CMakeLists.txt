cmake_minimum_required(VERSION 3.5)

# Project
project(xtd)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)
include(references.cmake)

if (XTD_BUILD_LIBRARIES_XTD_FORMS AND XTD_BUILD_LIBRARIES_XTD_DRAWING AND XTD_BUILD_LIBRARIES_XTD_CORE)
  add_definitions(-D__SYSTEM__REPORT__=1)
  set(SYSTEM_REPORT_FILES include/xtd/system_report.h include/xtd/system_report src/xtd/system_report.cpp)
endif ()

add_sources(
  include/xtd/xtd
  include/xtd/xtd
  include/xtd/xtd.h
  ${SYSTEM_REPORT_FILES}
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
