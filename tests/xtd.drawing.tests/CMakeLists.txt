cmake_minimum_required(VERSION 3.5)

project(xtd.drawing.tests)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)

if (XTD_BUILD_TESTS_XTD_FORMS)
  add_projects(
    xtd.drawing.lines.tests 
    xtd.drawing.rectangles.tests 
    xtd.drawing.rounded_rectangles.tests 
    xtd.drawing.strings.tests
  )
endif()
