cmake_minimum_required(VERSION 3.3)

project(tools)

if (IS_MAIN_PROJECT)
  option(ENABLE_XTDC_GUI_COMMAND_LINE "Enable xtdc-gui command line" ON)
else ()
  option(ENABLE_XTDC_GUI_COMMAND_LINE "Enable xtdc-gui command line" OFF)
endif ()

if (ENABLE_XTDC_GUI_COMMAND_LINE)
  add_subdirectory(xtdc-gui)
endif ()
