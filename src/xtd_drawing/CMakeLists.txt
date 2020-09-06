cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.drawing VERSION 0.0.1)

set(XTD_INCLUDES
  include/xtd/xtd.drawing
  include/xtd/xtd.drawing.h
)

set(XTD_DRAWING_INCLUDES
  include/xtd/drawing//bitmap.h
  include/xtd/drawing//brush.h
  include/xtd/drawing//brushes.h
  include/xtd/drawing/color.h
  include/xtd/drawing/dash_style.h
  include/xtd/drawing/font.h
  include/xtd/drawing/font_family.h
  include/xtd/drawing/font_style.h
  include/xtd/drawing/graphics.h
  include/xtd/drawing/graphics_unit.h
  include/xtd/drawing/hotkey_prefix.h
  include/xtd/drawing/icon.h
  include/xtd/drawing/image.h
  include/xtd/drawing/known_color.h
  include/xtd/drawing/pen.h
  include/xtd/drawing/pens.h
  include/xtd/drawing/point.h
  include/xtd/drawing/point_f.h
  include/xtd/drawing/rectangle.h
  include/xtd/drawing/rectangle_f.h
  include/xtd/drawing/size.h
  include/xtd/drawing/size_f.h
  include/xtd/drawing/solid_brush.h
  include/xtd/drawing/string_alignment.h
  include/xtd/drawing/string_format.h
  include/xtd/drawing/string_format_flags.h
  include/xtd/drawing/string_trimming.h
  include/xtd/drawing/system_brushes.h
  include/xtd/drawing/system_colors.h
  include/xtd/drawing/system_fonts.h
  include/xtd/drawing/system_icons.h
  include/xtd/drawing/system_images.h
  include/xtd/drawing/system_pens.h
)

set(XTD_DRAWING_DRAWING2D_INCLUDES
  include/xtd/drawing/drawing2d/linear_gradient_brush.h
  include/xtd/drawing/drawing2d/pen_alignment.h
  include/xtd/drawing/drawing2d/pen_type.h
)

set(XTD_DRAWING_IMAGING_INCLUDES
  include/xtd/drawing/imaging/color_palette.h
  include/xtd/drawing/imaging/frame_dimension.h
  include/xtd/drawing/imaging/image_flags.h
  include/xtd/drawing/imaging/image_format.h
  include/xtd/drawing/imaging/pixel_format.h
  include/xtd/drawing/imaging/property_item.h
)

set(XTD_DRAWING_TEXT_INCLUDES
  include/xtd/drawing/text/font_collection.h
  include/xtd/drawing/text/generic_font_families.h
  include/xtd/drawing/text/hotkey_prefix.h
  include/xtd/drawing/text/installed_font_collection.h
  include/xtd/drawing/text/private_font_collection.h
  include/xtd/drawing/text/text_rendering_hint.h
)

set(XTD_DRAWING_SOURCES
  src/xtd/drawing/bitmap.cpp
  src/xtd/drawing/brush.cpp
  src/xtd/drawing/brushes.cpp
  src/xtd/drawing/color.cpp
  src/xtd/drawing/font.cpp
  src/xtd/drawing/font_family.cpp
  src/xtd/drawing/graphics.cpp
  src/xtd/drawing/icon.cpp
  src/xtd/drawing/image.cpp
  src/xtd/drawing/pen.cpp
  src/xtd/drawing/pens.cpp
  src/xtd/drawing/point_f.cpp
  src/xtd/drawing/point.cpp
  src/xtd/drawing/rectangle_f.cpp
  src/xtd/drawing/rectangle.cpp
  src/xtd/drawing/size_f.cpp
  src/xtd/drawing/size.cpp
  src/xtd/drawing/solid_brush.cpp
  src/xtd/drawing/string_format.cpp
  src/xtd/drawing/system_brushes.cpp
  src/xtd/drawing/system_colors.cpp
  src/xtd/drawing/system_fonts.cpp
  src/xtd/drawing/system_images.cpp
  src/xtd/drawing/system_pens.cpp
)

set(XTD_DRAWING_DRAWING2D_SOURCES
  src/xtd/drawing/drawing2d/linear_gradient_brush.cpp
)

set(XTD_DRAWING_TEXT_SOURCES
  src/xtd/drawing/text/installed_font_collection.cpp
  src/xtd/drawing/text/private_font_collection.cpp
)

source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(include\\xtd\\drawing FILES ${XTD_DRAWING_INCLUDES})
source_group(include\\xtd\\drawing\\drawing2d FILES ${XTD_DRAWING_DRAWING2D_INCLUDES})
source_group(include\\xtd\\drawing\\imaging FILES ${XTD_DRAWING_IMAGING_INCLUDES})
source_group(include\\xtd\\drawing\\text FILES ${XTD_DRAWING_TEXT_INCLUDES})
source_group(src\\xtd\\drawing FILES ${XTD_DRAWING_SOURCES})
source_group(src\\xtd\\drawing\\drawing2d FILES ${XTD_DRAWING_DRAWING2D_SOURCES})
source_group(src\\xtd\\drawing\\text FILES ${XTD_DRAWING_TEXT_SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-D__XTD_DRAWING_RESOURCES_PATH__="${CMAKE_INSTALL_PREFIX}")

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_DRAWING_INCLUDES} ${XTD_DRAWING_DRAWING2D_INCLUDES} ${XTD_DRAWING_IMAGING_INCLUDES} ${XTD_DRAWING_TEXT_INCLUDES} ${XTD_DRAWING_SOURCES} ${XTD_DRAWING_DRAWING2D_SOURCES} ${XTD_DRAWING_TEXT_SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} xtd.core xtd.strings ${XTD_DRAWING_NATIVE_LIBRARY})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
