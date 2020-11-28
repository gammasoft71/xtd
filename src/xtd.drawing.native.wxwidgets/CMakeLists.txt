cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.drawing.native.wxwidgets)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
if (MSVC)
  add_compile_options(/wd5054)
elseif (APPLE)
  set(XTD_EXTRA_LIBS "-framework Cocoa")
elseif (UNIX)
  find_package(PkgConfig)
  pkg_check_modules(GTK gtk+-3.0)
  include_directories(${GTK_INCLUDE_DIRS})
  link_directories(${GTK_LIBRARY_DIRS})
  set(XTD_EXTRA_LIBS ${GTK_LIBRARIES})
endif()
find_package(wxWidgets REQUIRED COMPONENTS base core xrc)
include(${wxWidgets_USE_FILE})
add_include_directories(include)
add_references(xtd.drawing.native ${wxWidgets_LIBRARIES} ${XTD_EXTRA_LIBS})
add_sources(
  include/xtd/xtd.drawing.native.wxwidgets.h
  include/xtd/xtd.drawing.native.wxwidgets
  include/xtd/drawing/native/hdc_wrapper.h
  include/xtd/drawing/native/wx_application.h
  include/xtd/drawing/native/wx_brush.h
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
  src/xtd/drawing/native/wxwidgets/toolkit.cpp
)

if (APPLE)
  add_sources(
    src/xtd/drawing/native/wxwidgets/system_colors.mm
    src/xtd/drawing/native/wxwidgets/system_images.mm
  )
endif()
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
