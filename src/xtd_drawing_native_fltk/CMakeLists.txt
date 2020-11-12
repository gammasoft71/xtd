cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.drawing.native.fltk VERSION 0.0.1)

set(XTD_INCLUDES
  include/xtd/xtd.drawing.native.fltk.h
  include/xtd/xtd.drawing.native.fltk
)

set(XTD_DRAWING_NATIVE_INCLUDES
  include/xtd/drawing/native/fl_brush.h
  include/xtd/drawing/native/fl_dc.h
  include/xtd/drawing/native/fl_font.h
  include/xtd/drawing/native/fl_pen.h
)

set(XTD_DRAWING_NATIVE_FLTK_SOURCES
  src/xtd/drawing/native/fltk/brush.cpp
  src/xtd/drawing/native/fltk/font_family.cpp
  src/xtd/drawing/native/fltk/font.cpp
  src/xtd/drawing/native/fltk/graphics.cpp
  src/xtd/drawing/native/fltk/pen.cpp
  src/xtd/drawing/native/fltk/system_colors.cpp
  src/xtd/drawing/native/fltk/system_fonts.cpp
)

source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(include\\xtd\\drawing\\native FILES ${XTD_DRAWING_NATIVE_INCLUDES})
source_group(src\\xtd\\drawing\\native\\fltk FILES ${XTD_DRAWING_NATIVE_FLTK_SOURCES})

# Add packages
find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_DRAWING_NATIVE_INCLUDES} ${XTD_DRAWING_NATIVE_FLTK_SOURCES})
if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4996")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} xtd.drawing.native ${FLTK_LIBRARIES} xtd.strings)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
