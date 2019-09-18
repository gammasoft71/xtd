cmake_minimum_required(VERSION 3.3)

project(xtd.examples)

option(ADD_XT_CONSOLE "Add xtd.console example" ON)
option(ADD_XT_DELEGATES "Add xtd.delegates example" ON)
option(ADD_XT_DIAGNOSTICS "Add xtd.diagnostics example" ON)
option(ADD_XT_DRAWING "Add xtd.drawing example" ON)
option(ADD_XT_ENVIRONMENT "Add xtd.environment example" ON)
option(ADD_XT_FORMS "Add xtd.forms example" ON)
option(ADD_XT_IO "Add xtd.io example" ON)
option(ADD_XT_PROPERTIES "Add xtd.properties example" ON)
option(ADD_XT_STRINGS "Add xtd.strings example" ON)
option(ADD_XT_TUNIT "Add xtd.tunit example" ON)

if (ADD_XT_CONSOLE)
  add_subdirectory(hello_world_xtd_console)
endif()
  
if (ADD_XT_FORMS)
  add_subdirectory(hello_world_xtd_forms)
endif()
  
if (ADD_XT_TUNIT)
  add_subdirectory(hello_world_xtd_tunit)
endif()
  
if (ADD_XT_CONSOLE)
  add_subdirectory(../xtd.console/examples ${CMAKE_BINARY_DIR}/xtd.console/build)
endif()
  
  if (ADD_XT_DELEGATES)
add_subdirectory(../xtd.delegates/examples ${CMAKE_BINARY_DIR}/xtd.delegates/build)
endif()
  
if (ADD_XT_DIAGNOSTICS)
  add_subdirectory(../xtd.diagnostics/examples ${CMAKE_BINARY_DIR}/xtd.diagnostics/build)
endif()
  
if (ADD_XT_DRAWING)
  add_subdirectory(../xtd.drawing/examples .${CMAKE_BINARY_DIR}/xtd.drawing/build)
endif()
  
if (ADD_XT_ENVIRONMENT)
  add_subdirectory(../xtd.environment/examples ${CMAKE_BINARY_DIR}/xtd.environment/build)
endif()
  
if (ADD_XT_FORMS)
  add_subdirectory(../xtd.forms/examples ${CMAKE_BINARY_DIR}/xtd.forms/build)
endif()
  
if (ADD_XT_IO)
  add_subdirectory(../xtd.io/examples ${CMAKE_BINARY_DIR}/xtd.io/build)
endif()
  
if (ADD_XT_PROPERTIES)
  add_subdirectory(../xtd.properties/examples ${CMAKE_BINARY_DIR}/xtd.properties/build)
endif()
  
if (ADD_XT_STRINGS)
  add_subdirectory(../xtd.strings/examples ${CMAKE_BINARY_DIR}/xtd.strings/build)
endif()
  
if (ADD_XT_TUNIT)
  add_subdirectory(../xtd.tunit/examples ${CMAKE_BINARY_DIR}/xtd.tunit/build)
endif()
  