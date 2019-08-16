cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd)
set(EXPORT_PROJECT_NAME ${PROJECT_NAME})

# Options
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Projects
add_subdirectory(xtd.console/xtd.console)
add_subdirectory(xtd.delegates/xtd.delegates)
add_subdirectory(xtd.diagnostics/xtd.diagnostics)
add_subdirectory(xtd.drawing/xtd.drawing.native)
add_subdirectory(xtd.drawing/xtd.drawing.native.wxwidgets)
add_subdirectory(xtd.drawing/xtd.drawing)
add_subdirectory(xtd.environment/xtd.environment)
add_subdirectory(xtd.forms/xtd.forms.native)
#add_subdirectory(xtd.forms/xtd.forms.native.cocoa)
#add_subdirectory(xtd.forms/xtd.forms.native.gtk3)
#add_subdirectory(xtd.forms/xtd.forms.native.win32)
add_subdirectory(xtd.forms/xtd.forms.native.wxwidgets)
add_subdirectory(xtd.forms/xtd.forms)
add_subdirectory(xtd.io/xtd.io)
add_subdirectory(xtd.properties/xtd.properties)
add_subdirectory(xtd.strings/xtd.strings)
add_subdirectory(xtd.tunit/xtd.tunit)
add_subdirectory(xtd)
