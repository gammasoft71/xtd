cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd)

# Options
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Projects
add_subdirectory(xtd.console/xtd.console)
add_subdirectory(xtd.delegates/xtd.delegates)
add_subdirectory(xtd.properties/xtd.properties)
add_subdirectory(xtd.strings/xtd.strings)
add_subdirectory(xtd)
