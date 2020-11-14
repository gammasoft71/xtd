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
  xtd.forms.unit_tests
  xtd.tunit.manual_tests
  xtd.tunit.unit_tests
)
