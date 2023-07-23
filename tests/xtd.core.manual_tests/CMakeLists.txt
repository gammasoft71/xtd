cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.core.manual_tests)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_sources(src/manual_tests.cpp)
add_references(xtd.drawing)
target_type(CONSOLE_APPLICATION)
