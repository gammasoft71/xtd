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
  src/xtd/drawing/drawing_2d/tests/fill_mode_tests.cpp
  src/xtd/drawing/drawing_2d/tests/flush_intention_tests.cpp
  src/xtd/drawing/drawing_2d/tests/hatch_style_tests.cpp
  src/xtd/drawing/imaging/tests/encoder_parameter_value_type_tests.cpp
  src/xtd/drawing/tests/known_color_tests.cpp
  src/xtd/drawing/tests/color_tests.cpp
  src/xtd/drawing/tests/copy_pixel_operation_tests.cpp
  src/xtd/drawing/tests/dash_style_tests.cpp
  src/xtd/drawing/tests/font_style_tests.cpp
  src/xtd/drawing/tests/graphics_unit_tests.cpp
  src/xtd/drawing/tests/point_tests.cpp
  src/xtd/drawing/tests/size_tests.cpp
  src/xtd/drawing/text/tests/generic_font_families_tests.cpp
)
target_type(TEST_APPLICATION)
