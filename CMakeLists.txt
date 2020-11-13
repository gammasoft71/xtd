cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd)

# Options
option(XTD_ENABLE_COVERAGE "Enable code coverage" OFF)
option(XTD_ENABLE_COMPILER_OPTION_WARNINGS_AS_ERRORS "Enable compiler option warnings as errors" ON)
option(XTD_ENABLE_INSTALL_EXAMPLES "Enable install examples" ON)
option(XTD_ENABLE_INSTALL_RESOURCES "Enable install resources" ON)
option(XTD_BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(XTD_ENABLE_TESTS "Enable tests" OFF)
add_definitions(-D__XTD_RESOURCES_PATH__="${CMAKE_INSTALL_PREFIX}")

# incldue xtd_commands
include(scripts/cmake/xtd_commands.cmake)
include(scripts/cmake/xtd_version.cmake)

# Code coverage
if (XTD_ENABLE_COVERAGE AND UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage")
  set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} --coverage")
endif ()

# set xtd library type (shared or static)
if (XTD_BUILD_SHARED_LIBS)
  set(XTD_LIBRARY_TYPE SHARED_LIBRARY)
else()
  set(XTD_LIBRARY_TYPE STATIC_LIBRARY)
endif()

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

# Projects
add_projects(
  src
  tools
)

# Tests projects
if (XTD_ENABLE_TESTS)
  enable_testing()
  add_projects(tests)
endif ()

# install
install_package()
# override with specific switch cmake config file
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
install(FILES scripts/cmake/xtd_commands.cmake DESTINATION cmake)
install(EXPORT ${PROJECT_NAME} DESTINATION cmake)
if (XTD_ENABLE_INSTALL_RESOURCES)
  install(DIRECTORY resources DESTINATION share/xtd)
  install(DIRECTORY docs/pictures/examples/. DESTINATION share/xtd/resources/pictures/examples)
endif ()
if (XTD_ENABLE_INSTALL_EXAMPLES)
  install(DIRECTORY examples/. DESTINATION share/xtd/examples)
endif ()
