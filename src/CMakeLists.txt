cmake_minimum_required(VERSION 3.3)

# Solution
project(src)

# Projects
add_subdirectory(xtd_core)
if (IS_MAIN_PROJECT)
  #add_subdirectory(xtd_diagnostics)
  add_subdirectory(xtd_io)
  #add_subdirectory(xtd_registry)
  add_subdirectory(xtd_strings)
  add_subdirectory(xtd_tunit)
endif ()
