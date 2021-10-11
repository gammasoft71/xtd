cmake_minimum_required(VERSION 3.3)

# Project
project(themes)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

# Projects
add_projects(gnome_dark gnome_light macos_dark macos_light windows_dark windows_light)

# Install
if (XTD_INSTALL_RESOURCES)
  install(DIRECTORY . DESTINATION share/xtd/themes)
endif ()
