cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd)

# Options
option(XTD_BUILD_LIBRARIES_XTD_CORE "Build xtd.core libraries" ON)
option(XTD_BUILD_LIBRARIES_XTD_DRAWING "Build xtd.drawing libraries" ON)
option(XTD_BUILD_LIBRARIES_XTD_FORMS "Build xtd.forms libraries" ON)
option(XTD_BUILD_LIBRARIES_XTD_TUNIT "Build xtd.tunit libraries" ON)
option(XTD_BUILD_SHARED_LIBRARIES "Build shared libraries" OFF)
option(XTD_BUILD_TESTS_XTD_CORE "Build xtd.core tests" OFF)
option(XTD_BUILD_TESTS_XTD_DRAWING "Build xtd.drawing tests" OFF)
option(XTD_BUILD_TESTS_XTD_FORMS "Build xtd.forms tests" OFF)
option(XTD_BUILD_TESTS_XTD_TUNIT "Build xtd.tunit tests" OFF)
option(XTD_BUILD_TOOL_GUIDGEN_COMMAND_LINE "Build tool guidgen command line" ON)
option(XTD_BUILD_TOOL_GUIDGEN_GUI "Build tool guidgen GUI" ON)
option(XTD_BUILD_TOOL_XTDC_COMMAND_LINE "Build tool xtdc command line" ON)
option(XTD_BUILD_TOOL_XTDC_GUI "Enable tool xtdc-gui GUI" ON)
option(XTD_DOWNLOAD_DOXYGEN "Download and build doxygen from Github" OFF)
option(XTD_ENABLE_COMMAND_REFERENCE_GUIDE_GENERATOR "Enable command Reference Guide Generator" OFF)
option(XTD_ENABLE_COVERAGE "Enable code coverage" OFF)
option(XTD_INSTALL_EXAMPLES "Install examples" ON)
option(XTD_INSTALL_RESOURCES "Install resources" ON)
option(XTD_SET_COMPILER_OPTION_WARNINGS_TO_ALL "Enable compiler option warnings to all" ON)
option(XTD_SET_COMPILER_OPTION_WARNINGS_AS_ERRORS "Enable compiler option warnings as errors" ON)
add_definitions(-D__XTD_INSTALL_PATH__="${CMAKE_INSTALL_PREFIX}")
add_definitions(-D__XTD_RESOURCES_PATH__="${CMAKE_INSTALL_PREFIX}")

# incldue xtd_commands
include(scripts/cmake/xtd_commands.cmake)
include(scripts/cmake/xtd_version.cmake)

# Graphic toolkits definitions
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

# Code coverage
if (XTD_ENABLE_COVERAGE AND UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage")
  set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} --coverage")
endif ()

# set xtd library type (shared or static)
if (XTD_BUILD_SHARED_LIBRARIES)
  set(XTD_LIBRARY_TYPE SHARED_LIBRARY)
else()
  set(XTD_LIBRARY_TYPE STATIC_LIBRARY)
endif()

if (XTD_BUILD_TESTS_XTD_CORE OR XTD_BUILD_TESTS_XTD_DRAWING OR XTD_BUILD_TESTS_XTD_FORMS OR  XTD_BUILD_TESTS_XTD_TUNIT)
  enable_testing()
endif ()

# Projects
add_projects(src tests tools)

# install
install_package()
# override with specific xtd cmake config file
set(XTD_CONFIG_CMAKE_FILE ${CMAKE_CURRENT_BINARY_DIR}/xtdConfig.cmake)
file(WRITE "${XTD_CONFIG_CMAKE_FILE}"
  "include(CMakeFindDependencyMacro)\n"
  "include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\")\n"
  "include(\"\${CMAKE_CURRENT_LIST_DIR}/xtd_commands.cmake\")\n"
  "\n"
  "set(${PROJECT_NAME}_INCLUDE_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../include\")\n"
  "set(${PROJECT_NAME}_LIBRARIES_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../lib\")\n"
  "set(${PROJECT_NAME}_LIBRARIES ${PROJECT_NAME})\n"
  "set(${PROJECT_NAME}_FOUND TRUE)\n"
)
install(FILES scripts/cmake/xtd_commands.cmake DESTINATION cmake)
if (XTD_INSTALL_RESOURCES)
  install(DIRECTORY resources DESTINATION share/xtd)
  install(DIRECTORY docs/pictures/examples/. DESTINATION share/xtd/resources/pictures/examples)
endif ()
if (XTD_INSTALL_EXAMPLES)
  install(DIRECTORY examples/. DESTINATION share/xtd/examples)
endif ()
