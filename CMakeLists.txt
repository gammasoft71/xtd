cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd)
set(EXPORT_PROJECT_NAME ${PROJECT_NAME})

# Options
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
if (NOT DEFINED EXPORT_PROJECT_NAME)
  set(EXPORT_PROJECT_NAME ${PROJECT_NAME})
endif ()
add_definitions(-D__XTD_RESOURCES_PATH__="${CMAKE_INSTALL_PREFIX}")

# Add compile and link flags
option(XTD_ENABLE_COMPILER_OPTION_WARNINGS_TO_ALL "Enable compiler option warnings to all" ON)
option(XTD_ENABLE_COMPILER_OPTION_WARNINGS_AS_ERRORS "Enable compiler option warnings as errors" ON)
if (XTD_ENABLE_COMPILER_OPTION_WARNINGS_TO_ALL)
  if (MSVC)
    add_definitions(-D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)
    add_compile_options(/W4 /wd4100 /wd4127 /wd4458 /wd4996 /wd5105)
  else()
    add_compile_options(-Wall -Wextra -Wno-unused-parameter -Wno-gnu-zero-variadic-macro-arguments -pedantic)
  endif()
endif()
if (XTD_ENABLE_COMPILER_OPTION_WARNINGS_AS_ERRORS)
  if (MSVC)
    add_compile_options(/WX)
  else()
    add_compile_options(-Werror)
  endif()
endif()

# Code coverage
option(ENABLE_COVERAGE "Enable code coverage" OFF)
if (ENABLE_COVERAGE AND UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage")
  set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} --coverage")
endif ()

if (WIN32)
  #set(XTD_NATIVE_GRAPHIC_TOOLKIT "wsw" CACHE STRING "Choose toolkit for native drawing and forms libraries")
  set(XTD_NATIVE_GRAPHIC_TOOLKIT "wxwidgets" CACHE STRING "Choose toolkit for native drawing and forms libraries")
  set_property(CACHE XTD_NATIVE_GRAPHIC_TOOLKIT PROPERTY STRINGS fltk qt5 msw wxwidgets)
elseif (APPLE)
  #set(XTD_NATIVE_GRAPHIC_TOOLKIT "cocoa" CACHE STRING "Choose toolkit for native drawing and forms libraries")
  set(XTD_NATIVE_GRAPHIC_TOOLKIT "wxwidgets" CACHE STRING "Choose toolkit for native drawing and forms libraries")
  set_property(CACHE XTD_NATIVE_GRAPHIC_TOOLKIT PROPERTY STRINGS cocoa fltk qt5 wxwidgets)
else ()
  #set(XTD_NATIVE_GRAPHIC_TOOLKIT "gtk4" CACHE STRING "Choose toolkit for native drawing and forms libraries")
  set(XTD_NATIVE_GRAPHIC_TOOLKIT "wxwidgets" CACHE STRING "Choose toolkit for native drawing and forms libraries")
  set_property(CACHE XTD_NATIVE_GRAPHIC_TOOLKIT PROPERTY STRINGS fltk gtk3 gtk4 qt5 wxwidgets)
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
    "include(\"\${CMAKE_CURRENT_LIST_DIR}/xtd_commands.cmake\")\n"
    "\n"
    "set(${PROJECT_NAME}_INCLUDE_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../include\")\n"
    "set(${PROJECT_NAME}_LIBRARIES_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../lib\")\n"
    "set(${PROJECT_NAME}_LIBRARIES ${PROJECT_NAME})\n"
    "set(${PROJECT_NAME}_FOUND TRUE)\n"
  )
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake DESTINATION cmake)
  install(FILES scripts/cmake/xtd_commands.cmake DESTINATION cmake)
  install(EXPORT ${PROJECT_NAME} DESTINATION cmake)
  option(XTD_ENABLE_INSTALL_RESOURCES "Enable install resources" ON)
  if (XTD_ENABLE_INSTALL_RESOURCES)
    install(DIRECTORY resources DESTINATION share/xtd)
    install(DIRECTORY docs/pictures/examples/. DESTINATION share/xtd/resources/pictures/examples)
  endif ()
  option(XTD_ENABLE_INSTALL_EXAMPLES "Enable install examples" ON)
  if (XTD_ENABLE_INSTALL_EXAMPLES)
    install(DIRECTORY examples/. DESTINATION share/xtd/examples)
  endif ()
endif ()
