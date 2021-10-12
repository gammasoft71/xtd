cmake_minimum_required(VERSION 3.3)

# Project
project(themes)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

# Projects
add_projects(
  gnome_dark 
  gnome_light
  kde_dark 
  kde_light
  macos_dark
  macos_light
  windows_dark
  windows_light
  xtd_dark
  xtd_light
)

# Install
if (XTD_INSTALL_RESOURCES)
  install(DIRECTORY gnome_dark DESTINATION share/xtd/themes)
  install(DIRECTORY gnome_light DESTINATION share/xtd/themes)
  install(DIRECTORY kde_dark DESTINATION share/xtd/themes)
  install(DIRECTORY kde_light DESTINATION share/xtd/themes)
  install(DIRECTORY macos_dark DESTINATION share/xtd/themes)
  install(DIRECTORY macos_light DESTINATION share/xtd/themes)
  install(DIRECTORY symbolic_dark DESTINATION share/xtd/themes)
  install(DIRECTORY symbolic_light DESTINATION share/xtd/themes)
  install(DIRECTORY windows_dark DESTINATION share/xtd/themes)
  install(DIRECTORY windows_light DESTINATION share/xtd/themes)
  install(DIRECTORY xtd_dark DESTINATION share/xtd/themes)
  install(DIRECTORY xtd_light DESTINATION share/xtd/themes)
endif ()
