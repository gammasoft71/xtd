cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd.examples)

# Options
option(XTD_BUILD_EXAMPLES_XTD_CMAKE "Build xtd.cmake examples" ON)
option(XTD_BUILD_EXAMPLES_XTD_CORE "Build xtd.core examples" ON)
option(XTD_BUILD_EXAMPLES_XTD_DRAWING "Build xtd.drawing examples" ON)
option(XTD_BUILD_EXAMPLES_XTD_FORMS "Build xtd.forms examples" ON)
option(XTD_BUILD_EXAMPLES_XTD_TUNIT "Build xtd.tunit examples" ON)

# Find xtd package
find_package(xtd REQUIRED)

# Projects
if (XTD_BUILD_EXAMPLES_XTD_CMAKE)
  add_projects(xtd.cmake.examples)
endif()

if (XTD_BUILD_EXAMPLES_XTD_CORE)
  add_projects(xtd.core.examples)
endif()

if (XTD_BUILD_EXAMPLES_XTD_DRAWING)
  add_projects(xtd.drawing.examples)
endif()

if (XTD_BUILD_EXAMPLES_XTD_FORMS)
  add_projects(xtd.forms.examples)
endif()

if (XTD_BUILD_EXAMPLES_XTD_TUNIT)
  add_projects(xtd.tunit.examples)
endif()
