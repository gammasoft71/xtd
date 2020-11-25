cmake_minimum_required(VERSION 3.3)

# Solution
project(src)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

# Projects
if (XTD_BUILD_LIBRARIES_XTD_CORE)
  add_projects(xtd.3rdparty.call_stack xtd.core)
endif ()

if (XTD_BUILD_LIBRARIES_XTD_DRAWING)
  add_projects(xtd.drawing.native ${XTD_DRAWING_NATIVE_LIBRARY} xtd.drawing)
endif ()

if (XTD_BUILD_LIBRARIES_XTD_FORMS)
  add_projects(xtd.forms.native ${XTD_FORMS_NATIVE_LIBRARY} xtd.forms)
endif ()

if (XTD_BUILD_LIBRARIES_XTD_TUNIT)
  add_projects(xtd.tunit)
endif ()

add_projects(xtd)
