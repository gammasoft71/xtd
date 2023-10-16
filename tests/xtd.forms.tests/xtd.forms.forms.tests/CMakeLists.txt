cmake_minimum_required(VERSION 3.20)

# Projecs
project(xtd.forms.forms.tests)
add_references(xtd.forms)
include(../../../scripts/cmake/xtd_commands.cmake)
include(../../../scripts/cmake/xtd_version.cmake)
add_sources(src/forms.cpp)
target_type(GUI_APPLICATION)
