cmake_minimum_required(VERSION 3.5)

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
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
add_include_directories(include)
add_references(xtd.drawing.native xtd.core ${wxWidgets_LIBRARIES} ${XTD_EXTRA_LIBS})
add_sources(
  include/xtd/drawing/native/hdc_wrapper.h
  include/xtd/drawing/native/hdc_wrapper
  include/xtd/drawing/native/wx_application.h
  include/xtd/drawing/native/wx_application
  include/xtd/drawing/native/wx_brush.h
  include/xtd/drawing/native/wx_brush
  include/xtd/drawing/native/wx_pen.h
  include/xtd/drawing/native/wx_pen
  include/xtd/drawing/native/wxConicalGradient.h
  include/xtd/drawing/native/wxConicalGradient
  include/xtd/drawing/native/wxDrawString.h
  include/xtd/drawing/native/wxDrawString
  include/xtd/xtd.drawing.native.wxwidgets.h
  include/xtd/xtd.drawing.native.wxwidgets
  src/xtd/drawing/native/wxwidgets/brush.cpp
  src/xtd/drawing/native/wxwidgets/font.cpp
  src/xtd/drawing/native/wxwidgets/font_family.cpp
  src/xtd/drawing/native/wxwidgets/graphics.cpp
  src/xtd/drawing/native/wxwidgets/graphics_path.cpp
  src/xtd/drawing/native/wxwidgets/icon.cpp
  src/xtd/drawing/native/wxwidgets/image.cpp
  src/xtd/drawing/native/wxwidgets/matrix.cpp
  src/xtd/drawing/native/wxwidgets/pen.cpp
  src/xtd/drawing/native/wxwidgets/region.cpp
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
