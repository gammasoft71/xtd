cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd.console)

# External projects
include(ExternalProject)
ExternalProject_Add(catch GIT_REPOSITORY https://github.com/catchorg/Catch2.git GIT_TAG v2.6.0 GIT_SHALLOW 1 CMAKE_ARGS -DCATCH_BUILD_TESTING=OFF -DCATCH_INSTALL_DOCS=OFF -DCATCH_INSTALL_HELPERS=OFF -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR})
include_directories(SYSTEM ${CMAKE_BINARY_DIR}/include)

# Code coverage
option(ENABLE_COVERAGE "Enable code coverage" OFF)
if (ENABLE_COVERAGE AND UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage")
  set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} --coverage")
endif()

# Projects
add_subdirectory(xtd.console)
option(ENABLE_TESTS "Enable tests" ON)
if (ENABLE_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
