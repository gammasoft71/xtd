cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.drawing.native.fltk)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})
add_include_directories(include)
add_references(xtd.core xtd.drawing.native ${FLTK_LIBRARIES})
add_sources(
  include/xtd/xtd.drawing.native.fltk.h
  include/xtd/xtd.drawing.native.fltk
  include/xtd/drawing/native/fl_brush.h
  include/xtd/drawing/native/fl_dc.h
  include/xtd/drawing/native/fl_font.h
  include/xtd/drawing/native/fl_pen.h
  src/xtd/drawing/native/fltk/brush.cpp
  src/xtd/drawing/native/fltk/font_family.cpp
  src/xtd/drawing/native/fltk/font.cpp
  src/xtd/drawing/native/fltk/graphics.cpp
  src/xtd/drawing/native/fltk/pen.cpp
  src/xtd/drawing/native/fltk/system_colors.cpp
  src/xtd/drawing/native/fltk/system_fonts.cpp
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
