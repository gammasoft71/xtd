cmake_minimum_required(VERSION 3.3)

# Solution
project(src)

# Projects
add_subdirectory(xtd_forms_native)

if ("${XTD_NATIVE_TOOLKIT}" STREQUAL "cocoa")
  add_subdirectory(xtd_forms_native_cocoa)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.cocoa)
endif ()

if ("${XTD_NATIVE_TOOLKIT}" STREQUAL "fltk")
  add_subdirectory(xtd_forms_native_fltk)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.fltk)
endif ()

if ("${XTD_NATIVE_TOOLKIT}" STREQUAL "gtk3")
  add_subdirectory(xtd_forms_native_gtk3)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.gtk3)
endif ()

if ("${XTD_NATIVE_TOOLKIT}" STREQUAL "qt5")
  add_subdirectory(xtd_forms_native_qt5)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.fltk)
endif ()

if ("${XTD_NATIVE_TOOLKIT}" STREQUAL "msw")
  add_subdirectory(xtd_forms_native_win32)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.win32)
endif ()

option(XTD_WXWIDGETS "Use wxWidgets as native drawing and forms libraries" ON)
if (XTD_WXWIDGETS)
  add_subdirectory(xtd_forms_native_wxwidgets)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.wxwidgets)
endif ()

if (IS_MAIN_PROJECT)
  add_subdirectory(xtd_delegates)
  add_subdirectory(xtd_diagnostics)
  add_subdirectory(xtd_core)
  add_subdirectory(xtd_drawing)
  add_subdirectory(xtd_io)
  add_subdirectory(xtd_strings)
  add_subdirectory(xtd_tunit)
endif ()

add_subdirectory(xtd_forms)
