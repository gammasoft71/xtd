cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.drawing.unit_tests)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_references(xtd.drawing)
add_sources(
  src/main.cpp 
  src/xtd/drawing/drawing_2d/tests/compositing_mode_tests.cpp
  src/xtd/drawing/drawing_2d/tests/compositing_quality_tests.cpp
  src/xtd/drawing/tests/known_color_tests.cpp
  src/xtd/drawing/tests/color_tests.cpp
  src/xtd/drawing/tests/copy_pixel_operation_tests.cpp
  src/xtd/drawing/tests/point_tests.cpp
  src/xtd/drawing/tests/size_tests.cpp
)
target_type(TEST_APPLICATION)
