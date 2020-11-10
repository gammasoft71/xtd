cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd.forms)

# Options
set(CMAKE_DEBUG_POSTFIX d)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(IS_MAIN_PROJECT OFF)
if (NOT DEFINED EXPORT_PROJECT_NAME)
  set(IS_MAIN_PROJECT ON)
  set(EXPORT_PROJECT_NAME ${PROJECT_NAME})
endif ()
add_definitions(-D__XTD_FORMS_RESOURCES_PATH__="${CMAKE_INSTALL_PREFIX}")

# Add compile and link flags
option(XTD_ENABLE_COMPILER_OPTION_WARNINGS_TO_ALL "Enable compiler option warnings to all" ON)
option(XTD_ENABLE_COMPILER_OPTION_WARNINGS_AS_ERRORS "Enable compiler option warnings as errors" ON)
if (XTD_ENABLE_COMPILER_OPTION_WARNINGS_TO_ALL)
  if (MSVC)
    add_definitions(-D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)
    add_compile_options(/W4 /wd4100 /wd4458 /wd4996)
  else()
    add_compile_options(-Wall -Wextra -Wno-unused-parameter -pedantic)
  endif()
endif()
if (XTD_ENABLE_COMPILER_OPTION_WARNINGS_AS_ERRORS)
  if (MSVC)
    add_compile_options(/WX)
  else()
    add_compile_options(-Werror)
  endif()
endif()

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
add_subdirectory(tools)

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
    "if (APPLE)\n"
    "#  find_package(wxWidgets REQUIRED COMPONENTS base core aui html gl net qa richtext webview xml xrc)\n"
    "  find_package(wxWidgets REQUIRED COMPONENTS base core aui html net qa richtext webview xml xrc)\n"
    "elseif (UNIX)\n"
    "  find_package(wxWidgets REQUIRED COMPONENTS base core aui html gl net qa richtext xml xrc)\n"
    "else ()\n"
    "  find_package(wxWidgets REQUIRED COMPONENTS base core aui html gl net qa richtext webview xml xrc)\n"
    "endif ()\n"
    "\n"
    "set(${PROJECT_NAME}_INCLUDE_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../include\")\n"
    "set(${PROJECT_NAME}_LIBRARIES_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../lib\")\n"
    "set(${PROJECT_NAME}_LIBRARIES ${PROJECT_NAME})\n"
    "set(${PROJECT_NAME}_FOUND TRUE)\n"
  )
  
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake DESTINATION cmake)
  install(FILES src/xtd_core/scripts/cmake/xtd_commands.cmake DESTINATION cmake)
  install(EXPORT xtd.forms DESTINATION cmake)
  option(XTD_ENABLE_INSTALL_RESOURCES "Enable install resources" ON)
  if (XTD_ENABLE_INSTALL_RESOURCES)
    install(DIRECTORY resources DESTINATION share/xtd)
  endif ()
endif ()
