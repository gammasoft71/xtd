cmake_minimum_required(VERSION 3.3)

project(tools)

add_subdirectory(guid)
option(ENABLE_XTD_COMMAND_LINE "Enable xtd command line" ON)
if (ENABLE_XTD_COMMAND_LINE)
  add_subdirectory(xtdc)
endif ()
