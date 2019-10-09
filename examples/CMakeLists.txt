cmake_minimum_required(VERSION 3.3)

project(xtd.examples)

option(ADD_XT_CONSOLE "Add xtd.console example" ON)
option(ADD_XT_DELEGATES "Add xtd.delegates example" ON)
option(ADD_XT_DIAGNOSTICS "Add xtd.diagnostics example" ON)
option(ADD_XT_DRAWING "Add xtd.drawing example" ON)
option(ADD_XT_FORMS "Add xtd.forms example" ON)
option(ADD_XT_IO "Add xtd.io example" ON)
option(ADD_XT_PROPERTIES "Add xtd.properties example" ON)
option(ADD_XT_STRINGS "Add xtd.strings example" ON)
option(ADD_XT_SYSTEM "Add xtd.system example" ON)
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
  add_subdirectory(../src/xtd_console/examples ${CMAKE_BINARY_DIR}/xtd_console/build)
endif()
  
  if (ADD_XT_DELEGATES)
add_subdirectory(../src/xtd_delegates/examples ${CMAKE_BINARY_DIR}/xtd_delegates/build)
endif()
  
if (ADD_XT_DIAGNOSTICS)
  add_subdirectory(../src/xtd_diagnostics/examples ${CMAKE_BINARY_DIR}/xtd_diagnostics/build)
endif()
  
if (ADD_XT_DRAWING)
  add_subdirectory(../src/xtd_drawing/examples .${CMAKE_BINARY_DIR}/xtd_drawing/build)
endif()
  
if (ADD_XT_FORMS)
  add_subdirectory(../src/xtd_forms/examples ${CMAKE_BINARY_DIR}/xtd_forms/build)
endif()
  
if (ADD_XT_IO)
  add_subdirectory(../src/xtd_io/examples ${CMAKE_BINARY_DIR}/xtd_io/build)
endif()
  
if (ADD_XT_PROPERTIES)
  add_subdirectory(../src/xtd_properties/examples ${CMAKE_BINARY_DIR}/xtd_properties/build)
endif()
  
if (ADD_XT_STRINGS)
  add_subdirectory(../src/xtd_strings/examples ${CMAKE_BINARY_DIR}/xtd_strings/build)
endif()
  
if (ADD_XT_SYSTEM)
  add_subdirectory(../src/xtd_system/examples ${CMAKE_BINARY_DIR}/xtd_system/build)
endif()
  
if (ADD_XT_TUNIT)
  add_subdirectory(../src/xtd_tunit/examples ${CMAKE_BINARY_DIR}/xtd_tunit/build)
endif()
  