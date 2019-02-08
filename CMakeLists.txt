cmake_minimum_required(VERSION 3.3)

# Solution
project(console)

# Options
if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
else ()
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/${CMAKE_CURRENT_BINARY_DIR})
endif ()

enable_testing()

# External projects
include(ExternalProject)
ExternalProject_Add(catch GIT_REPOSITORY https://github.com/catchorg/Catch2.git GIT_TAG v2.6.0 GIT_SHALLOW 1 CMAKE_ARGS -DCATCH_BUILD_TESTING=OFF -DCATCH_INSTALL_DOCS=OFF -DCATCH_INSTALL_HELPERS=OFF -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR})
include_directories(SYSTEM ${CMAKE_BINARY_DIR}/include)

# Projects
add_subdirectory(console)
add_subdirectory(tests)
