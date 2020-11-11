cmake_minimum_required(VERSION 3.3)

project(xtd.examples)
find_package(xtd REQUIRED)

option(XTD_ENABLE_CMAKE_EXAMPLES "Enable xtd.cmake examples" ON)
if (XTD_ENABLE_CMAKE_EXAMPLES)
  add_projects(xtd.cmake.examples)
endif()

option(XTD_ENABLE_CORE_EXAMPLES "Enable xtd.core examples" ON)
if (XTD_ENABLE_CORE_EXAMPLES)
  add_projects(xtd.core.examples)
endif()

option(XTD_ENABLE_DRAWING_EXAMPLES "Enable xtd.drawing examples" ON)
if (XTD_ENABLE_DRAWING_EXAMPLES)
  add_projects(xtd.drawing.examples)
endif()

option(XTD_ENABLE_FORMS_EXAMPLES "Enable xtd.forms examples" ON)
if (XTD_ENABLE_FORMS_EXAMPLES)
  add_projects(xtd.forms.examples)
endif()

option(XTD_ENABLE_TUNIT_EXAMPLES "Enable xtd.tunit examples" ON)
if (XTD_ENABLE_TUNIT_EXAMPLES)
  add_projects(xtd.tunit.examples)
endif()
