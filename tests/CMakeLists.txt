cmake_minimum_required(VERSION 3.3)

project(tests)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

add_projects(
  xtd.core.manual_tests
  xtd.core.unit_tests
  xtd.drawing.manual_tests
  xtd.drawing.unit_tests
  xtd.forms.manual_tests
)

if (not XTD_DISABLE_FROMS_TESTS)
  add_projects(xtd.forms.unit_tests)
endif()

add_projects(
  xtd.tunit.manual_tests
  xtd.tunit.unit_tests
)
