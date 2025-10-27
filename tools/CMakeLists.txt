cmake_minimum_required(VERSION 3.20)

# Solution
project(tools)
include("../scripts/cmake/xtd_commands.cmake")
include("../scripts/cmake/xtd_version.cmake")

# Add projects
add_projects(
  demangler
  guidgen
  sleepfor
  set_environment_variable
  set_path
  xtdc
)

if (NOT (${XTD_OPERATING_SYSTEM_NAME} STREQUAL "Android" OR ${XTD_OPERATING_SYSTEM_NAME} STREQUAL "Haiku" OR ${XTD_OPERATING_SYSTEM_NAME} STREQUAL "SerenityOS" OR ${XTD_OPERATING_SYSTEM_NAME} STREQUAL "iOS"))
  add_projects(
    guidgen-gui
    keycodes
    xtdc-gui
  )
endif ()