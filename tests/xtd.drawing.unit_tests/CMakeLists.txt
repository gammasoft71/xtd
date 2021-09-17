cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.drawing.unit_tests)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_references(xtd.drawing)
add_sources(
  src/main.cpp 
  src/xtd/drawing/color.cpp
  src/xtd/drawing/point.cpp
  src/xtd/drawing/size.cpp
)
target_type(TEST_APPLICATION)
