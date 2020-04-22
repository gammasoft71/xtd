cmake_minimum_required(VERSION 3.3)

project(xtd.examples)
find_package(xtd.console REQUIRED)

option(ADD_XTD_CMAKE_HELPERS "Add xtd CMake Helpers example" ON)
option(ADD_XTD_CONSOLE "Add xtd.console example" ON)
#option(ADD_XTD_CORE "Add xtd.core example" ON)
#option(ADD_XTD_DELEGATES "Add xtd.delegates example" ON)
#option(ADD_XTD_DIAGNOSTICS "Add xtd.diagnostics example" ON)
#option(ADD_XTD_DRAWING "Add xtd.drawing example" ON)
option(ADD_XTD_FORMS "Add xtd.forms example" ON)
#option(ADD_XTD_IO "Add xtd.io example" ON)
#option(ADD_XTD_PROPERTIES "Add xtd.properties example" ON)
#option(ADD_XTD_STRINGS "Add xtd.strings example" ON)
option(ADD_XTD_TUNIT "Add xtd.tunit example" ON)

if (ADD_XTD_CMAKE_HELPERS)
  add_projects(cmake_helpers)
endif()

if (ADD_XTD_CONSOLE)
  add_projects(hello_world_xtd_console)
endif()
  
if (ADD_XTD_FORMS)
  add_projects(hello_world_xtd_forms)
endif()
  
if (ADD_XTD_TUNIT)
  add_projects(hello_world_xtd_tunit)
endif()
  
if (ADD_XTD_CONSOLE)
#  add_projects(../src/xtd_console/examples ${CMAKE_BINARY_DIR}/xtd_console/build)
endif()
  
if (ADD_XTD_CORE)
#  add_projects(../src/xtd_core/examples ${CMAKE_BINARY_DIR}/xtd_core/build)
endif()
  
if (ADD_XTD_DELEGATES)
#  add_projects(../src/xtd_delegates/examples ${CMAKE_BINARY_DIR}/xtd_delegates/build)
endif()
  
if (ADD_XTD_DIAGNOSTICS)
#  add_projects(../src/xtd_diagnostics/examples ${CMAKE_BINARY_DIR}/xtd_diagnostics/build)
endif()
  
if (ADD_XTD_DRAWING)
#  add_projects(../src/xtd_drawing/examples .${CMAKE_BINARY_DIR}/xtd_drawing/build)
endif()
  
if (ADD_XTD_FORMS)
#  add_projects(../src/xtd_forms/examples ${CMAKE_BINARY_DIR}/xtd_forms/build)
endif()
  
if (ADD_XTD_IO)
#  add_projects(../src/xtd_io/examples ${CMAKE_BINARY_DIR}/xtd_io/build)
endif()
  
if (ADD_XTD_PROPERTIES)
#  add_projects(../src/xtd_properties/examples ${CMAKE_BINARY_DIR}/xtd_properties/build)
endif()
  
if (ADD_XTD_STRINGS)
#  add_projects(../src/xtd_strings/examples ${CMAKE_BINARY_DIR}/xtd_strings/build)
endif()
  
if (ADD_XTD_TUNIT)
#  add_projects(../src/xtd_tunit/examples ${CMAKE_BINARY_DIR}/xtd_tunit/build)
endif()
 