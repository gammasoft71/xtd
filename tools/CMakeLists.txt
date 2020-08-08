cmake_minimum_required(VERSION 3.3)

project(tools)

option(XTD_ENABLE_GUIDGEN_COMMAND_LINE "Enable guidgen command line" ON)
if (XTD_ENABLE_GUIDGEN_COMMAND_LINE)
  add_subdirectory(guidgen)
  endif ()

option(XTD_ENABLE_COMMAND_LINE "Enable xtd command line" ON)
if (XTD_ENABLE_COMMAND_LINE)
  add_subdirectory(xtdc)
endif ()
