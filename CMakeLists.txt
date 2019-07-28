cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd.forms)

# Options
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(EXPORT_PROJECT_NAME ${PROJECT_NAME})

# Code coverage
option(ENABLE_COVERAGE "Enable code coverage" OFF)
if (ENABLE_COVERAGE AND UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage")
  set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} --coverage")
endif()

# Projects
add_subdirectory(xtd.forms.native)
#add_subdirectory(xtd.forms.native.cocoa)
#add_subdirectory(xtd.forms.native.gtk3)
#add_subdirectory(xtd.forms.native.win32)
add_subdirectory(xtd.forms.native.wxwidgets)
add_subdirectory(xtd.forms)
add_subdirectory(xtd.drawing/xtd.drawing.native)
add_subdirectory(xtd.drawing/xtd.drawing.native.wxwidgets)
add_subdirectory(xtd.drawing/xtd.drawing)
add_subdirectory(xtd.delegates/xtd.delegates)
add_subdirectory(xtd.diagnostics/xtd.diagnostics)
add_subdirectory(xtd.environment/xtd.environment)
add_subdirectory(xtd.io/xtd.io)
add_subdirectory(xtd.strings/xtd.strings)
option(ENABLE_TESTS "Enable tests" OFF)
if (ENABLE_TESTS)
  enable_testing()
  add_subdirectory(xtd.tunit/xtd.tunit)
  add_subdirectory(tests)
endif()

# install
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
"include(CMakeFindDependencyMacro)\n"
"include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\")\n"
"\n"
"find_package(xtd.drawing REQUIRED)\n"
"find_package(xtd.delegates REQUIRED)\n"
"find_package(xtd.diagnostics REQUIRED)\n"
"find_package(xtd.environment REQUIRED)\n"
"find_package(xtd.io REQUIRED)\n"
"find_package(xtd.strings REQUIRED)\n"
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
