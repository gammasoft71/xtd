cmake_minimum_required(VERSION 3.20)

project(tests)
include("../scripts/cmake/xtd_commands.cmake")
include("../scripts/cmake/xtd_version.cmake")

add_projects(
  xtd.core.manual_tests
  xtd.core.unit_tests
  xtd.tunit.manual_tests
  xtd.tunit.unit_tests
)

if (NOT (${XTD_OPERATING_SYSTEM_NAME} STREQUAL "Android" OR ${XTD_OPERATING_SYSTEM_NAME} STREQUAL "Haiku" OR ${XTD_OPERATING_SYSTEM_NAME} STREQUAL "iOS"))
  add_projects(
    xtd.drawing.manual_tests
    xtd.drawing.unit_tests
    xtd.forms.manual_tests
    xtd.forms.unit_tests
    xtd.drawing.tests
    xtd.forms.tests
  )
endif ()
