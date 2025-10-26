cmake_minimum_required(VERSION 3.20)

project(tests)
include("../scripts/cmake/xtd_commands.cmake")
include("../scripts/cmake/xtd_version.cmake")

if (XTD_BUILD_TESTS_XTD_CORE)
  add_projects(
    xtd.core.manual_tests
    xtd.core.unit_tests
  )
endif ()

if (NOT (${XTD_OPERATING_SYSTEM_NAME} STREQUAL "Android" OR ${XTD_OPERATING_SYSTEM_NAME} STREQUAL "Haiku" OR ${XTD_OPERATING_SYSTEM_NAME} STREQUAL "SerenityOS" OR ${XTD_OPERATING_SYSTEM_NAME} STREQUAL "iOS"))
  if (XTD_BUILD_TESTS_XTD_DRAWING)
    add_projects(
      xtd.drawing.manual_tests
      xtd.drawing.unit_tests
      xtd.drawing.tests
    )
  endif ()

  if (XTD_BUILD_TESTS_XTD_FORMS)
    add_projects(
      xtd.forms.manual_tests
      xtd.forms.unit_tests
      xtd.forms.tests
    )
  endif ()
endif ()

if (XTD_BUILD_TESTS_XTD_TUNIT)
  add_projects(
    xtd.tunit.manual_tests
    xtd.tunit.unit_tests
  )
endif ()
