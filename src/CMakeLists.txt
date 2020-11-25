cmake_minimum_required(VERSION 3.3)

# Solution
project(src)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

set(XTD_HEADER_FILE "xtd/include/xtd/xtd.h")
file(WRITE ${XTD_HEADER_FILE} "#pragma once\n")

# Projects
if (XTD_BUILD_LIBRARIES_XTD_CORE)
  add_projects(xtd.3rdparty.call_stack xtd.core)
  file(APPEND ${XTD_HEADER_FILE} "#include \"xtd/xtd.core\"\n")
endif ()

if (XTD_BUILD_LIBRARIES_XTD_DRAWING)
  add_projects(xtd.drawing.native ${XTD_DRAWING_NATIVE_LIBRARY} xtd.drawing)
  file(APPEND ${XTD_HEADER_FILE} "#include \"xtd/xtd.drawing\"\n")
endif ()

if (XTD_BUILD_LIBRARIES_XTD_FORMS)
  add_projects(xtd.forms.native ${XTD_FORMS_NATIVE_LIBRARY} xtd.forms)
  file(APPEND ${XTD_HEADER_FILE} "#include \"xtd/xtd.forms\"\n")
endif ()

if (XTD_BUILD_LIBRARIES_XTD_TUNIT)
  add_projects(xtd.tunit)
  file(APPEND ${XTD_HEADER_FILE} "#include \"xtd/xtd.tunit\"\n")
endif ()

add_projects(xtd)
