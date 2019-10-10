cmake_minimum_required(VERSION 3.3)

# Solution
project(src)

# Projects
add_subdirectory(xtd_delegates)
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  add_subdirectory(xtd_tunit)
endif ()
