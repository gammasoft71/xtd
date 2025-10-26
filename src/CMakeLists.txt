cmake_minimum_required(VERSION 3.20)

# Solution
project(src)
include("../scripts/cmake/xtd_commands.cmake")
include("../scripts/cmake/xtd_version.cmake")

# Remarks : 
# for 3rdparty libraries don't forget modify target_type macro (SHARED_LIBRARY) in scripts/cmake/xtd_command.cmake file to skip target_link_libraries with xtd.core

# Projects
add_projects(
  xtd.core.native 
  ${XTD_CORE_NATIVE_LIBRARY} 
  xtd.core
)

if (NOT (${XTD_OPERATING_SYSTEM_NAME} STREQUAL "Android" OR ${XTD_OPERATING_SYSTEM_NAME} STREQUAL "Haiku" OR ${XTD_OPERATING_SYSTEM_NAME} STREQUAL "SerenityOS" OR ${XTD_OPERATING_SYSTEM_NAME} STREQUAL "iOS"))
  add_projects(
    xtd.drawing.native 
    ${XTD_DRAWING_NATIVE_LIBRARY}
    xtd.drawing
    xtd.forms.native
    ${XTD_FORMS_NATIVE_LIBRARY}
    xtd.forms
  )
endif()

add_projects(
  xtd.tunit
  xtd
)
