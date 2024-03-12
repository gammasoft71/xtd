cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.drawing.manual_tests)
add_references(xtd.drawing xtd.tunit)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_sources(src/manual_tests.cpp)
target_type(CONSOLE_APPLICATION)
