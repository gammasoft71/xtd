cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.core.manual_tests)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_references(xtd.tunit xtd.forms)
add_sources(src/manual_tests.cpp)
target_type(CONSOLE_APPLICATION)
