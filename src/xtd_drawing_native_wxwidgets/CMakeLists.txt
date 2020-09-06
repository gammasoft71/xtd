cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.drawing.native.wxwidgets VERSION 0.0.1)

set(XTD_INCLUDES
  include/xtd/xtd.drawing.native.wxwidgets.h
  include/xtd/xtd.drawing.native.wxwidgets
)

set(XTD_DRAWING_NATIVE_INCLUDES
  include/xtd/drawing/native/hdc_wrapper.h
  include/xtd/drawing/native/wx_brush.h
)

set(XTD_DRAWING_NATIVE_WXWIDGETS_SOURCES
  src/xtd/drawing/native/wxwidgets/brush.cpp
  src/xtd/drawing/native/wxwidgets/font.cpp
  src/xtd/drawing/native/wxwidgets/font_family.cpp
  src/xtd/drawing/native/wxwidgets/graphics.cpp
  src/xtd/drawing/native/wxwidgets/icon.cpp
  src/xtd/drawing/native/wxwidgets/image.cpp
  src/xtd/drawing/native/wxwidgets/pen.cpp
  src/xtd/drawing/native/wxwidgets/system_colors.cpp
  src/xtd/drawing/native/wxwidgets/system_images.cpp
  src/xtd/drawing/native/wxwidgets/system_images_gtk.cpp
  src/xtd/drawing/native/wxwidgets/system_fonts.cpp
)

if (APPLE)
  set(XTD_DRAWING_NATIVE_WXWIDGETS_SOURCES ${XTD_DRAWING_NATIVE_WXWIDGETS_SOURCES}
    src/xtd/drawing/native/wxwidgets/system_colors.mm
    src/xtd/drawing/native/wxwidgets/system_images.mm
  )
endif()

source_group(include\\xtd FILES ${XTD_INCLUDES})
source_group(include\\xtd\\drawing\\native FILES ${XTD_DRAWING_NATIVE_INCLUDES})
source_group(src\\xtd\\drawing\\native\\wxwidgets FILES ${XTD_DRAWING_NATIVE_WXWIDGETS_SOURCES})

# Add packages
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

if (APPLE)
  set(XTD_EXTRA_LIBS "-framework Cocoa")
elseif (UNIX)
  find_package(PkgConfig)
  pkg_check_modules(GTK gtk+-3.0)
  include_directories(${GTK_INCLUDE_DIRS})
  link_directories(${GTK_LIBRARY_DIRS})
  set(XTD_EXTRA_LIBS ${GTK_LIBRARIES})
endif()

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${XTD_INCLUDES} ${XTD_DRAWING_NATIVE_INCLUDES} ${XTD_DRAWING_NATIVE_WXWIDGETS_SOURCES})
if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4996")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} xtd.drawing.native xtd.io xtd.strings ${wxWidgets_LIBRARIES} ${XTD_EXTRA_LIBS})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
