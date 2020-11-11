cmake_minimum_required(VERSION 3.3)

project(xtd.examples)
find_package(xtd REQUIRED)

option(ADD_XTD_CMAKE_HELPERS "Add xtd CMake Helpers example" ON)
option(ADD_XTD_CORE "Add xtd.core example" ON)
option(ADD_XTD_DRAWING "Add xtd.drawing example" ON)
option(ADD_XTD_FORMS "Add xtd.forms example" ON)
option(ADD_XTD_TUNIT "Add xtd.tunit example" ON)

if (ADD_XTD_CMAKE_HELPERS)
  add_projects(cmake_helpers)
endif()

if (ADD_XTD_CORE)
  add_projects(xtd.core)
endif()
  
if (ADD_XTD_DRAWING)
  add_projects(xtd.drawing)
endif()
  
if (ADD_XTD_FORMS)
  add_projects(xtd.forms)
endif()
  
if (ADD_XTD_TUNIT)
#  add_projects(xtd.tunit)
endif()
