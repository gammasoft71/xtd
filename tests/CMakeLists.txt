cmake_minimum_required(VERSION 3.3)

project(tests)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

if (XTD_BUILD_TESTS_XTD_CORE)
  add_projects(xtd.core.manual_tests xtd.core.unit_tests)
endif()
  
if (XTD_BUILD_TESTS_XTD_DRAWING)
  add_projects(xtd.drawing.manual_tests xtd.drawing.unit_tests)
endif()

if (XTD_BUILD_TESTS_XTD_FORMS)
  add_projects(xtd.forms.manual_tests xtd.forms.unit_tests)
endif()

if (XTD_BUILD_TESTS_XTD_TUNIT)
  add_projects(xtd.tunit.manual_tests xtd.tunit.unit_tests)
endif()
