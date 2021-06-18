cmake_minimum_required(VERSION 3.3)

# Solution
project(tools)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

# Add projects
if (XTD_BUILD_TOOL_GUIDGEN_COMMAND_LINE)
  add_projects(guidgen)
endif ()
if (XTD_BUILD_TOOL_GUIDGEN_GUI)
  add_projects(guidgen-gui)
endif ()
if (XTD_BUILD_TOOL_SLEEPFOR_COMMAND_LINE)
  add_projects(sleepfor)
endif ()
if (XTD_BUILD_TOOL_XTDC_COMMAND_LINE)
  add_projects(xtdc)
endif ()
if (XTD_BUILD_TOOL_XTDC_GUI)
  add_projects(xtdc-gui)
endif ()
