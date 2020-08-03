cmake_minimum_required(VERSION 3.3)

project(tools)

option(ENABLE_XTDC_GUI_COMMAND_LINE "Enable xtdc-gui command line" ON)
if (ENABLE_XTDC_GUI_COMMAND_LINE)
  add_subdirectory(xtdc-gui)
endif ()
