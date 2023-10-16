cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.forms.tool_bars.tests)
add_references(xtd.forms)
include(../../../scripts/cmake/xtd_commands.cmake)
include(../../../scripts/cmake/xtd_version.cmake)
add_sources(src/tool_bars.cpp)
target_type(GUI_APPLICATION)
