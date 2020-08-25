cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.drawing.native VERSION 0.0.1)

set(XTD_INCLUDES
  include/xtd/xtd.drawing.native.h
  include/xtd/xtd.drawing.native
)

set(XTD_DRAWING_NATIVE_INCLUDES
  include/xtd/drawing/native/argb.h
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
  include/xtd/drawing/native/theme.h
)

set(SOURCES
  src/xtd.drawing.native.cpp
)

source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(include\\xtd\\drawing\\native FILES ${XTD_DRAWING_NATIVE_INCLUDES})
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_DRAWING_NATIVE_INCLUDES} ${SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} xtd.core xtd.strings)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
