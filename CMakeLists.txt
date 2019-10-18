cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd.drawing)

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
add_subdirectory(xtd.drawing.native)

option(XTD_COCOA "Use Apple AppKit libraries as native drawing and forms libraries" OFF)
if (XTD_COCOA)
  add_subdirectory(xtd.drawing.native.cocoa)
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.cocoa)
endif ()

option(XTD_FLTK "Use FLTK as native drawing and forms libraries" OFF)
if (XTD_FLTK)
  add_subdirectory(xtd.drawing.native.fltk)
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.fltk)
endif ()

option(XTD_GTK "Use Gtk+3 as native drawing and forms libraries" OFF)
if (XTD_GTK)
  add_subdirectory(xtd.drawing.native.gtk3)
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.gtk3)
endif ()

option(XTD_QT5 "Use Qt as native drawing and forms libraries" OFF)
if (XTD_QT5)
  add_subdirectory(xtd.drawing.native.qt5)
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.fltk)
endif ()

option(XTD_WIN32 "Use Microsoft Win32 api as native drawing and forms libraries" OFF)
if (XTD_WIN32)
  add_subdirectory(xtd.drawing.native.win32)
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.win32)
endif ()

option(XTD_WXWIDGETS "Use wxWidgets as native drawing and forms libraries" ON)
if (XTD_WXWIDGETS)
  add_subdirectory(xtd.drawing.native.wxwidgets)
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.wxwidgets)
endif ()

add_subdirectory(xtd.drawing)
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  add_subdirectory(xtd.strings)
  add_subdirectory(xtd.tunit)
endif ()

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
    "endif ()\n"
  )
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake DESTINATION cmake)
  install(EXPORT ${PROJECT_NAME} DESTINATION cmake)
endif ()
