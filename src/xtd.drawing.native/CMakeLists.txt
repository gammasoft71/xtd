cmake_minimum_required(VERSION 3.5)

# Project
project(xtd.drawing.native)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)
add_sources(
  include/xtd/xtd.drawing.native
  include/xtd/xtd.drawing.native.h
  include/xtd/drawing/native/brush.h
  include/xtd/drawing/native/compositing_modes.h
  include/xtd/drawing/native/compositing_qualities.h
  include/xtd/drawing/native/copy_pixel_operations.h
  include/xtd/drawing/native/flush_intentions.h
  include/xtd/drawing/native/font_family.h
  include/xtd/drawing/native/font.h
  include/xtd/drawing/native/frame_dimension.h
  include/xtd/drawing/native/graphics_path.h
  include/xtd/drawing/native/graphics.h
  include/xtd/drawing/native/hot_key_prefixes.h
  include/xtd/drawing/native/icon.h
  include/xtd/drawing/native/image_flags.h
  include/xtd/drawing/native/image_formats.h
  include/xtd/drawing/native/image.h
  include/xtd/drawing/native/interpolation_modes.h
  include/xtd/drawing/native/line_caps.h
  include/xtd/drawing/native/line_joins.h
  include/xtd/drawing/native/matrix_orders.h
  include/xtd/drawing/native/matrix.h
  include/xtd/drawing/native/path_fill_modes.h
  include/xtd/drawing/native/pen.h
  include/xtd/drawing/native/pixel_offset_modes.h
  include/xtd/drawing/native/region.h
  include/xtd/drawing/native/rotate_flip_types.h
  include/xtd/drawing/native/smoothing_modes.h
  include/xtd/drawing/native/string_alignments.h
  include/xtd/drawing/native/string_formats.h
  include/xtd/drawing/native/string_trimmings.h
  include/xtd/drawing/native/system_colors.h
  include/xtd/drawing/native/system_fonts.h
  include/xtd/drawing/native/system_images.h
  include/xtd/drawing/native/text_rendering.h
  include/xtd/drawing/native/toolkit.h
)
target_type(INTERFACE_LIBRARY)

# Install
add_install_include_directories(include/xtd)
install_component()
