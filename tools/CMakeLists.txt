cmake_minimum_required(VERSION 3.3)

project(tools)

if (IS_MAIN_PROJECT)
  option(ENABLE_GUIDGEN_COMMAND_LINE "Enable guidgen command line" ON)
else ()
  option(ENABLE_GUIDGEN_COMMAND_LINE "Enable guidgen command line" OFF)
endif ()
if (ENABLE_GUIDGEN_COMMAND_LINE)
  add_subdirectory(guidgen)
  endif ()

if (IS_MAIN_PROJECT)
  option(ENABLE_XTD_COMMAND_LINE "Enable xtd command line" ON)
else ()
  option(ENABLE_XTD_COMMAND_LINE "Enable xtd command line" OFF)
endif ()

if (ENABLE_XTD_COMMAND_LINE)
  add_subdirectory(xtdc)
endif ()
