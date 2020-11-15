cmake_minimum_required(VERSION 3.3)

# Solution
project(src)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

# set drawing and forms native library
if ("${XTD_NATIVE_GRAPHIC_TOOLKIT}" STREQUAL "cocoa")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.cocoa)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.cocoa)
endif ()
if ("${XTD_NATIVE_GRAPHIC_TOOLKIT}" STREQUAL "fltk")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.fltk)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.fltk)
endif ()
if ("${XTD_NATIVE_GRAPHIC_TOOLKIT}" STREQUAL "gtk3")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.gtk3)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.gtk3)
endif ()
if ("${XTD_NATIVE_GRAPHIC_TOOLKIT}" STREQUAL "gtk4")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.gtk4)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.gtk4)
endif ()
if ("${XTD_NATIVE_GRAPHIC_TOOLKIT}" STREQUAL "qt5")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.qt5)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.fltk)
endif ()
if ("${XTD_NATIVE_GRAPHIC_TOOLKIT}" STREQUAL "msw")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.win32)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.win32)
endif ()
if ("${XTD_NATIVE_GRAPHIC_TOOLKIT}" STREQUAL "wxwidgets")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.wxwidgets)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.wxwidgets)
endif ()

# Projects
add_projects(
  xtd.3rdparty.call_stack
  xtd.core
  xtd.drawing.native
  ${XTD_DRAWING_NATIVE_LIBRARY}
  xtd.drawing
  xtd.forms.native
  ${XTD_FORMS_NATIVE_LIBRARY}
  xtd.forms
  xtd.tunit
  xtd
)
