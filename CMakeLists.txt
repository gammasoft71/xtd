cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd.drawing)

# Options
set(CMAKE_DEBUG_POSTFIX d)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(IS_MAIN_PROJECT OFF)
if (NOT DEFINED EXPORT_PROJECT_NAME)
  set(IS_MAIN_PROJECT ON)
  set(EXPORT_PROJECT_NAME ${PROJECT_NAME})
endif ()

if (WIN32)
  #set(XTD_NATIVE_TOOLKIT "wsw" CACHE STRING "Choose toolkit for native drawing and forms libraries")
  set(XTD_NATIVE_TOOLKIT "wxwidgets" CACHE STRING "Choose toolkit for native drawing and forms libraries")
  set_property(CACHE XTD_NATIVE_TOOLKIT PROPERTY STRINGS fltk qt5 msw wxwidgets)
elseif (APPLE)
  #set(XTD_NATIVE_TOOLKIT "cocoa" CACHE STRING "Choose toolkit for native drawing and forms libraries")
  set(XTD_NATIVE_TOOLKIT "wxwidgets" CACHE STRING "Choose toolkit for native drawing and forms libraries")
  set_property(CACHE XTD_NATIVE_TOOLKIT PROPERTY STRINGS cocoa fltk qt5 wxwidgets)
else ()
  #set(XTD_NATIVE_TOOLKIT "gtk4" CACHE STRING "Choose toolkit for native drawing and forms libraries")
  set(XTD_NATIVE_TOOLKIT "wxwidgets" CACHE STRING "Choose toolkit for native drawing and forms libraries")
  set_property(CACHE XTD_NATIVE_TOOLKIT PROPERTY STRINGS fltk gtk3 gtk4 qt5 wxwidgets)
endif ()

# Code coverage
option(ENABLE_COVERAGE "Enable code coverage" OFF)
if (ENABLE_COVERAGE AND UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage")
  set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} --coverage")
endif ()

# Projects
add_subdirectory(src)

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
    "include(\"\${CMAKE_CURRENT_LIST_DIR}/xtd_commands.cmake\")\n"
    "\n"
    "find_package(wxWidgets REQUIRED)\n"
    "\n"
    "set(${PROJECT_NAME}_INCLUDE_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../include\")\n"
    "set(${PROJECT_NAME}_LIBRARIES_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../lib\")\n"
    "set(${PROJECT_NAME}_LIBRARIES ${PROJECT_NAME})\n"
    "set(${PROJECT_NAME}_FOUND TRUE)\n"
  )
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake DESTINATION cmake)
  install(FILES src/xtd_core/scripts/cmake/xtd_commands.cmake DESTINATION cmake)
  install(EXPORT ${PROJECT_NAME} DESTINATION cmake)
  option(XTD_ENABLE_INSTALL_RESOURCES "Enable install resources" ON)
  if (XTD_ENABLE_INSTALL_RESOURCES)
    install(DIRECTORY resources DESTINATION share/xtd)
  endif ()
endif ()
