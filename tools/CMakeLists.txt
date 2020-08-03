cmake_minimum_required(VERSION 3.3)

project(tools)

option(ENABLE_GUIDGEN_COMMAND_LINE "Enable guidgen command line" ON)
if (ENABLE_GUIDGEN_COMMAND_LINE)
  add_subdirectory(guidgen)
  endif ()

option(ENABLE_XTD_COMMAND_LINE "Enable xtd command line" ON)
if (ENABLE_XTD_COMMAND_LINE)
  add_subdirectory(xtdc)
endif ()
