cmake_minimum_required(VERSION 3.3)

# Options
option(XTD_ENABLE_TOOL_GUIDGEN_COMMAND_LINE "Enable tool guidgen command line" ON)
option(XTD_ENABLE_TOOL_GUIDGEN_GUI "Enable tool guidgen GUI" ON)
option(XTD_ENABLE_TOOL_XTDC_COMMAND_LINE "Enable tool xtdc command line" ON)
option(XTD_ENABLE_TOOL_XTDC_GUI "Enable tool xtdc-gui GUI" ON)

# Solution
project(tools)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

# Add projects
if (XTD_ENABLE_TOOL_GUIDGEN_COMMAND_LINE)
  add_projects(guidgen)
endif ()
if (XTD_ENABLE_TOOL_GUIDGEN_GUI)
  add_projects(guidgen-gui)
endif ()
if (XTD_ENABLE_TOOL_XTDC_COMMAND_LINE)
  add_projects(xtdc)
endif ()
if (XTD_ENABLE_TOOL_XTDC_GUI)
  add_projects(xtdc-gui)
endif ()
