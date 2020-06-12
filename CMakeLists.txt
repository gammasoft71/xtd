cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd.forms)

# Options
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(IS_MAIN_PROJECT OFF)
if (NOT DEFINED EXPORT_PROJECT_NAME)
  set(IS_MAIN_PROJECT ON)
  set(EXPORT_PROJECT_NAME ${PROJECT_NAME})
endif ()
add_definitions(-D__XTD_FORMS_RESOURCES_PATH__="${CMAKE_INSTALL_PREFIX}")

# Code coverage
option(ENABLE_COVERAGE "Enable code coverage" OFF)
if (ENABLE_COVERAGE AND UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage")
  set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} --coverage")
endif ()

# Projects

# if we want to use native libraries for testing we can't include src project but dependent projects instead
#add_subdirectory(src)

add_subdirectory(src/xtd_forms_native)

if (APPLE)
  option(XTD_COCOA "Use Apple AppKit libraries as native drawing and forms libraries (not implemented yet)" OFF)
  if (XTD_COCOA)
    add_subdirectory(src/xtd_forms_native_cocoa)
    set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.cocoa)
  endif ()
endif ()

option(XTD_FLTK "Use FLTK as native drawing and forms libraries (not implemented yet)" OFF)
if (XTD_FLTK)
  add_subdirectory(src/xtd_forms_native_fltk)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.fltk)
endif ()

option(XTD_GTK "Use Gtk+3 as native drawing and forms libraries (not implemented yet)" OFF)
if (XTD_GTK)
  add_subdirectory(src/xtd_forms_native_gtk3)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.gtk3)
endif ()

option(XTD_QT5 "Use Qt as native drawing and forms libraries (not implemented yet)" OFF)
if (XTD_QT5)
  add_subdirectory(src/xtd_forms_native_qt5)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.fltk)
endif ()

if (MSVC)
  option(XTD_WIN32 "Use Microsoft Win32 api as native drawing and forms libraries (not implemented yet)" OFF)
  if (XTD_WIN32)
    add_subdirectory(src/xtd_forms_native_win32)
    set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.win32)
  endif ()
endif ()

option(XTD_WXWIDGETS "Use wxWidgets as native drawing and forms libraries" ON)
if (XTD_WXWIDGETS)
  add_subdirectory(src/xtd_forms_native_wxwidgets)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.wxwidgets)
  add_definitions(-D__XTD_FORMS_NATIVE_WXWIDGETS__)
endif ()

if (IS_MAIN_PROJECT)
  add_subdirectory(src/xtd_delegates)
  add_subdirectory(src/xtd_diagnostics)
  add_subdirectory(src/xtd_core)
  add_subdirectory(src/xtd_drawing)
  add_subdirectory(src/xtd_io)
  add_subdirectory(src/xtd_strings)
  add_subdirectory(src/xtd_tunit)
endif ()

add_subdirectory(src/xtd_forms)

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
    "set(XTD_PROJECT_INCLUDE_FILE \"xtd/xtd.forms\")\n"
    "include(\"\${CMAKE_CURRENT_LIST_DIR}/xtd_commands.cmake\")\n"
    "\n"
    "find_package(wxWidgets REQUIRED)\n"
    "\n"
    "get_filename_component(${PROJECT_NAME}_INCLUDE_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../include\" ABSOLUTE)\n"
    "get_filename_component(${PROJECT_NAME}_LIBRARIES_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../lib\" ABSOLUTE)\n"
    "\n"
    "set(${PROJECT_NAME}_LIBRARIES ${PROJECT_NAME})\n"
    "set(${PROJECT_NAME}_FOUND TRUE)\n"
  )
  
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake DESTINATION cmake)
  install(FILES src/xtd_core/scripts/cmake/xtd_commands.cmake DESTINATION cmake)
  install(EXPORT xtd.forms DESTINATION cmake)
  install(DIRECTORY resources DESTINATION share/xtd)
endif ()
