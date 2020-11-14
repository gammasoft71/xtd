cmake_minimum_required(VERSION 3.3)

# Options
option(XTD_ENABLE_GUIDGEN_COMMAND_LINE "Enable guidgen command line" ON)
option(XTD_ENABLE_COMMAND_LINE "Enable xtd command line" ON)
option(XTD_ENABLE_GUI_COMMAND_LINE "Enable xtdc-gui command line" ON)

# Solution
project(tools)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

# Add projects
if (XTD_ENABLE_GUIDGEN_COMMAND_LINE)
  add_projects(guidgen)
endif ()
if (XTD_ENABLE_COMMAND_LINE)
  add_projects(xtdc)
endif ()
if (XTD_ENABLE_GUI_COMMAND_LINE)
  add_projects(xtdc-gui)
endif ()
