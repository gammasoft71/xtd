cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd.drawing)

# Options
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(IS_MAIN_PROJECT OFF)
if (NOT DEFINED EXPORT_PROJECT_NAME)
  set(IS_MAIN_PROJECT ON)
  set(EXPORT_PROJECT_NAME ${PROJECT_NAME})
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
    "get_filename_component(${PROJECT_NAME}_INCLUDE_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../include\" ABSOLUTE)\n"
    "get_filename_component(${PROJECT_NAME}_LIBRARIES_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../lib\" ABSOLUTE)\n"
    "\n"
    "set(${PROJECT_NAME}_LIBRARIES ${PROJECT_NAME})\n"
    "set(${PROJECT_NAME}_FOUND TRUE)\n"
  )
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake DESTINATION cmake)
  install(EXPORT ${PROJECT_NAME} DESTINATION cmake)
  install(DIRECTORY resources DESTINATION share/xtd)
endif ()
