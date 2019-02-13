cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd)

# Options
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Code coverage
option(ENABLE_COVERAGE "Enable code coverage" OFF)
if (ENABLE_COVERAGE AND UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage")
  set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} --coverage")
endif()

# Projects
add_subdirectory(xtd.strings)
option(ENABLE_TESTS "Enable tests" ON)
if (ENABLE_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
