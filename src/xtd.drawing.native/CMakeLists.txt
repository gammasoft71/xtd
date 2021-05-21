cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.drawing.native)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)
add_sources(
  include/xtd/xtd.drawing.native
  include/xtd/xtd.drawing.native.h
  include/xtd/drawing/native/brush.h
  include/xtd/drawing/native/font.h
  include/xtd/drawing/native/font_family.h
  include/xtd/drawing/native/frame_dimension.h
  include/xtd/drawing/native/graphics.h
  include/xtd/drawing/native/icon.h
  include/xtd/drawing/native/image.h
  include/xtd/drawing/native/image_flags.h
  include/xtd/drawing/native/image_format.h
  include/xtd/drawing/native/pen.h
  include/xtd/drawing/native/system_colors.h
  include/xtd/drawing/native/system_images.h
  include/xtd/drawing/native/system_fonts.h
  include/xtd/drawing/native/toolkit.h
)
target_type(INTERFACE_LIBRARY)

# Install
add_install_include_directories(include/xtd)
install_component()
