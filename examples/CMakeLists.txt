cmake_minimum_required(VERSION 3.3)

project(xtd.examples)
find_package(xtd REQUIRED)

option(XTD_ENABLE_CMAKE_HELPERS_EXAMPLES "Enable xtd CMake Helpers example" ON)
if (XTD_ENABLE_CMAKE_HELPERS_EXAMPLES)
  add_projects(cmake_helpers)
endif()

option(XTD_ENABLE_CORE_EXAMPLES "Enable xtd.core example" ON)
if (XTD_ENABLE_CORE_EXAMPLES)
  add_projects(xtd.core)
endif()

option(XTD_ENABLE_DRAWING_EXAMPLES "Enable xtd.drawing example" ON)
if (XTD_ENABLE_DRAWING_EXAMPLES)
  add_projects(xtd.drawing)
endif()

option(XTD_ENABLE_FORMS_EXAMPLES "Enable xtd.forms example" ON)
if (XTD_ENABLE_FORMS_EXAMPLES)
  add_projects(xtd.forms)
endif()

option(XTD_ENABLE_TUNIT_EXAMPLES "Enable xtd.tunit example" ON)
if (XTD_ENABLE_TUNIT_EXAMPLES)
  add_projects(xtd.tunit)
endif()
