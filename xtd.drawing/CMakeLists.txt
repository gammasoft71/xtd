cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.drawing VERSION 0.0.1)

set(XTD_INCLUDES
  include/xtd/xtd.drawing
  include/xtd/xtd.drawing.hpp
)

set(XTD_DRAWING_INCLUDES
  include/xtd/drawing/color.hpp
  include/xtd/drawing//known_color.hpp
  include/xtd/drawing//point.hpp
  include/xtd/drawing//size.hpp
  include/xtd/drawing//system_colors.hpp
)

set(XTD_DRAWING_SOURCES
  src/xtd/drawing/drawing.cpp
  src/xtd/drawing/color.cpp
  src/xtd/drawing/point.cpp
  src/xtd/drawing/size.cpp
  src/xtd/drawing/system_colors.cpp
)

source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(include\\xtd\\drawing FILES ${XTD_DRAWING_INCLUDES})
source_group(src\\xtd\\drawing FILES ${XTD_DRAWING_SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_DRAWING_INCLUDES} ${XTD_DRAWING_SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} xtd.strings xtd.drawing.native.wxwidgets)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
