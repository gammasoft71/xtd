cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd)
set(EXPORT_PROJECT_NAME ${PROJECT_NAME})

# Options
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(EXPORT_PROJECT_NAME ${PROJECT_NAME})

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

# install
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  "include(CMakeFindDependencyMacro)\n"
  "include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\")\n"
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
