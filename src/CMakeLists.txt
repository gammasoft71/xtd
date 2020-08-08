cmake_minimum_required(VERSION 3.3)

# Solution
project(src)

# Projects

if (IS_MAIN_PROJECT)
  add_subdirectory(xtd_core)
  add_subdirectory(xtd_delegates)
  #add_subdirectory(xtd_diagnostics)
  add_subdirectory(xtd_io)
  add_subdirectory(xtd_strings)
  add_subdirectory(xtd_tunit)  
endif ()

add_subdirectory(xtd_drawing_native)

if ("${XTD_NATIVE_TOOLKIT}" STREQUAL "cocoa")
  add_subdirectory(xtd_drawing_native_cocoa)
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.cocoa)
endif ()

if ("${XTD_NATIVE_TOOLKIT}" STREQUAL "fltk")
  add_subdirectory(xtd_drawing_native_fltk)
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.fltk)
endif ()

if ("${XTD_NATIVE_TOOLKIT}" STREQUAL "gtk3")
  add_subdirectory(xtd_drawing_native_gtk3)
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.gtk3)
endif ()

if ("${XTD_NATIVE_TOOLKIT}" STREQUAL "qt5")
  add_subdirectory(xtd_drawing_native_qt5)
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.fltk)
endif ()

if ("${XTD_NATIVE_TOOLKIT}" STREQUAL "msw")
  add_subdirectory(xtd_drawing_native_win32)
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.win32)
endif ()

if ("${XTD_NATIVE_TOOLKIT}" STREQUAL "wxwidgets")
  add_subdirectory(xtd_drawing_native_wxwidgets)
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.wxwidgets)
endif ()

add_subdirectory(xtd_drawing)
