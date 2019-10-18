cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd.forms)

# Options
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
if (NOT DEFINED EXPORT_PROJECT_NAME)
  set(EXPORT_PROJECT_NAME ${PROJECT_NAME})
endif ()

# Code coverage
option(ENABLE_COVERAGE "Enable code coverage" OFF)
if (ENABLE_COVERAGE AND UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage")
  set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} --coverage")
endif ()

# Projects
add_subdirectory(xtd.forms.native)

option(XTD_COCOA "Use Apple AppKit libraries as native drawing and forms libraries" OFF)
if (XTD_COCOA)
  add_subdirectory(xtd.forms.native.cocoa)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.cocoa)
endif ()

option(XTD_FLTK "Use FLTK as native drawing and forms libraries" OFF)
if (XTD_FLTK)
  add_subdirectory(xtd.forms.native.fltk)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.fltk)
endif ()

option(XTD_GTK "Use Gtk+3 as native drawing and forms libraries" OFF)
if (XTD_GTK)
  add_subdirectory(xtd.forms.native.gtk3)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.gtk3)
endif ()

option(XTD_FORMS_QT5 "Use Qt as native drawing and forms libraries" OFF)
if (XTD_FORMS_QT5)
  add_subdirectory(xtd.forms.native.qt5)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.fltk)
endif ()

option(XTD_WIN32 "Use Microsoft Win32 api as native drawing and forms libraries" OFF)
if (XTD_WIN32)
  add_subdirectory(xtd.forms.native.win32)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.win32)
endif ()

option(XTD_WXWIDGETS "Use wxWidgets as native drawing and forms libraries" ON)
if (XTD_WXWIDGETS)
  add_subdirectory(xtd.forms.native.wxwidgets)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.wxwidgets)
endif ()

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  add_subdirectory(xtd.delegates)
  add_subdirectory(xtd.diagnostics)
  add_subdirectory(xtd.environment)
  add_subdirectory(xtd.drawing)
  add_subdirectory(xtd.io)
  add_subdirectory(xtd.strings)
  add_subdirectory(xtd.tunit)
endif ()

add_subdirectory(xtd.forms)

# Tests projects
option(ENABLE_TESTS "Enable tests" OFF)
if (ENABLE_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif ()

# install
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    "include(CMakeFindDependencyMacro)\n"
    "include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\")\n"
    "\n"
    "find_package(wxWidgets REQUIRED)\n"
    "\n"
    "get_filename_component(${PROJECT_NAME}_INCLUDE_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../include\" ABSOLUTE)\n"
    "get_filename_component(${PROJECT_NAME}_LIBRARIES_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../lib\" ABSOLUTE)\n"
    "\n"
    "set(${PROJECT_NAME}_LIBRARIES ${PROJECT_NAME})\n"
    "set(${PROJECT_NAME}_FOUND TRUE)\n"
    "\n"
    "set(CMAKE_CXX_STANDARD 17)\n"
    "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n"
    "if (MSVC)\n"
    "  set(CMAKE_CXX_FLAGS \"\${CMAKE_CXX_FLAGS} /utf-8\")\n"
    "  set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup\")\n"
    "endif ()\n"
  )
  
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake DESTINATION cmake)
  install(EXPORT xtd.forms DESTINATION cmake)
endif ()
